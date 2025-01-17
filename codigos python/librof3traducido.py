from PyPDF2 import PdfReader
from docx import Document
import os

# Ruta del archivo original y los archivos generados
input_path = "d:\\Users\\usuario\\Desktop\\Libro Fisica 3.pdf"
output_text_path = "d:\\Users\\usuario\\Desktop\\Libro_Fisica_3_Traducido.docx"

# Verificar si el archivo de entrada existe
if not os.path.exists(input_path):
    print(f"El archivo {input_path} no existe.")
else:
    try:
        # Leer el contenido del PDF original
        reader = PdfReader(input_path)

        # Crear un documento de Word para guardar el texto limpio y traducido
        doc = Document()

        # Extraer texto, omitiendo fórmulas y elementos irrelevantes
        for page in reader.pages:
            text = page.extract_text()
            if text:
                # Filtrar líneas con fórmulas usando heurísticas simples
                clean_text = "\n".join([line for line in text.splitlines() if not any(c in line for c in "=+-*/()[]")])
                doc.add_paragraph(clean_text)

        # Guardar el texto limpio en un archivo de Word
        doc.save(output_text_path)
        print(f"El archivo traducido se ha guardado en {output_text_path}")
    except Exception as e:
        print(f"Hubo un error al procesar el archivo: {e}")