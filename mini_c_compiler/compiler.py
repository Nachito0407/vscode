import sys

# ============================================================
# 1) TOKEN
# ============================================================

class Token:
    def __init__(self, kind, value=None):
        self.kind = kind
        self.value = value

    def __repr__(self):
        if self.value is None:
            return f"Token({self.kind})"
        return f"Token({self.kind}, {self.value})"


# ============================================================
# 2) LEXER
# Convierte texto C en tokens
# ============================================================

class Lexer:
    def __init__(self, text):
        self.text = text
        self.pos = 0

    def current_char(self):
        if self.pos >= len(self.text):
            return None
        return self.text[self.pos]

    def advance(self):
        self.pos += 1

    def skip_whitespace(self):
        while self.current_char() is not None and self.current_char().isspace():
            self.advance()

    def number(self):
        result = ""

        while self.current_char() is not None and self.current_char().isdigit():
            result += self.current_char()
            self.advance()

        return Token("NUMBER", int(result))

    def identifier(self):
        result = ""

        while (
            self.current_char() is not None
            and (self.current_char().isalnum() or self.current_char() == "_")
        ):
            result += self.current_char()
            self.advance()

        if result == "int":
            return Token("INT")

        if result == "return":
            return Token("RETURN")

        return Token("IDENT", result)

    def get_next_token(self):
        self.skip_whitespace()

        ch = self.current_char()

        if ch is None:
            return Token("EOF")

        if ch.isdigit():
            return self.number()

        if ch.isalpha() or ch == "_":
            return self.identifier()

        if ch == "+":
            self.advance()
            return Token("PLUS")

        if ch == "-":
            self.advance()
            return Token("MINUS")

        if ch == "*":
            self.advance()
            return Token("MUL")

        if ch == "/":
            self.advance()
            return Token("DIV")

        if ch == "(":
            self.advance()
            return Token("LPAREN")

        if ch == ")":
            self.advance()
            return Token("RPAREN")

        if ch == "{":
            self.advance()
            return Token("LBRACE")

        if ch == "}":
            self.advance()
            return Token("RBRACE")

        if ch == ";":
            self.advance()
            return Token("SEMICOLON")

        raise SyntaxError(f"Caracter no reconocido: {ch}")


# ============================================================
# 3) NODOS DEL AST
# ============================================================

class NumberNode:
    def __init__(self, value):
        self.value = value


class BinOpNode:
    def __init__(self, left, op, right):
        self.left = left
        self.op = op
        self.right = right


class ReturnNode:
    def __init__(self, expr):
        self.expr = expr


class ProgramNode:
    def __init__(self, body):
        self.body = body


# ============================================================
# 4) PARSER
# Convierte tokens en AST
# ============================================================

class Parser:
    def __init__(self, lexer):
        self.lexer = lexer
        self.current_token = self.lexer.get_next_token()

    def eat(self, kind):
        if self.current_token.kind == kind:
            self.current_token = self.lexer.get_next_token()
        else:
            raise SyntaxError(
                f"Se esperaba {kind}, pero llegó {self.current_token.kind}"
            )

    def parse(self):
        return self.program()

    def program(self):
        # int main() { return expr; }

        self.eat("INT")

        if self.current_token.kind != "IDENT" or self.current_token.value != "main":
            raise SyntaxError("Se esperaba la función main")

        self.eat("IDENT")
        self.eat("LPAREN")
        self.eat("RPAREN")
        self.eat("LBRACE")

        body = self.return_statement()

        self.eat("RBRACE")
        self.eat("EOF")

        return ProgramNode(body)

    def return_statement(self):
        self.eat("RETURN")
        expr = self.expr()
        self.eat("SEMICOLON")
        return ReturnNode(expr)

    # expr maneja + y -
    def expr(self):
        node = self.term()

        while self.current_token.kind in ("PLUS", "MINUS"):
            op = self.current_token.kind

            if op == "PLUS":
                self.eat("PLUS")
            else:
                self.eat("MINUS")

            right = self.term()
            node = BinOpNode(node, op, right)

        return node

    # term maneja * y /
    def term(self):
        node = self.factor()

        while self.current_token.kind in ("MUL", "DIV"):
            op = self.current_token.kind

            if op == "MUL":
                self.eat("MUL")
            else:
                self.eat("DIV")

            right = self.factor()
            node = BinOpNode(node, op, right)

        return node

    # factor maneja números y paréntesis
    def factor(self):
        token = self.current_token

        if token.kind == "NUMBER":
            self.eat("NUMBER")
            return NumberNode(token.value)

        if token.kind == "LPAREN":
            self.eat("LPAREN")
            node = self.expr()
            self.eat("RPAREN")
            return node

        raise SyntaxError(f"Factor inválido: {token}")


# ============================================================
# 5) GENERADOR DE ASSEMBLY
# Genera Assembly x86-64 AT&T para GCC
# ============================================================

class CodeGenerator:
    def __init__(self):
        self.code = []

    def emit(self, line):
        self.code.append(line)

    def generate(self, program):
        self.emit(".globl main")
        self.emit("main:")

        self.generate_statement(program.body)

        return "\n".join(self.code)

    def generate_statement(self, node):
        if isinstance(node, ReturnNode):
            self.generate_expr(node.expr)

            # El resultado queda en %rax.
            # main devuelve el valor en eax/rax.
            self.emit("    ret")
        else:
            raise TypeError("Nodo de sentencia no soportado")

    def generate_expr(self, node):
        if isinstance(node, NumberNode):
            self.emit(f"    mov ${node.value}, %rax")
            return

        if isinstance(node, BinOpNode):
            # Evaluar lado derecho primero.
            self.generate_expr(node.right)

            # Guardar resultado derecho en la pila.
            self.emit("    push %rax")

            # Evaluar lado izquierdo.
            self.generate_expr(node.left)

            # Sacar lado derecho en %rbx.
            self.emit("    pop %rbx")

            if node.op == "PLUS":
                self.emit("    add %rbx, %rax")

            elif node.op == "MINUS":
                self.emit("    sub %rbx, %rax")

            elif node.op == "MUL":
                self.emit("    imul %rbx, %rax")

            elif node.op == "DIV":
                # División entera:
                # rax = lado izquierdo
                # rbx = lado derecho
                self.emit("    cqo")
                self.emit("    idiv %rbx")

            else:
                raise TypeError(f"Operación no soportada: {node.op}")

            return

        raise TypeError("Nodo de expresión no soportado")


# ============================================================
# 6) MAIN
# ============================================================

def main():
    if len(sys.argv) != 2:
        print("Uso:")
        print("python compiler.py archivo.c")
        sys.exit(1)

    input_file = sys.argv[1]

    with open(input_file, "r", encoding="utf-8") as f:
        source_code = f.read()

    lexer = Lexer(source_code)
    parser = Parser(lexer)
    ast = parser.parse()

    generator = CodeGenerator()
    asm_code = generator.generate(ast)

    with open("out.s", "w", encoding="utf-8") as f:
        f.write(asm_code + "\n")

    print("Compilación terminada.")
    print("Archivo generado: out.s")


if __name__ == "__main__":
    main()