import speedtest

def bits_to_mbps(bits):
    return round(bits / 1_000_000, 2)  # Convertir bits a Mbps y redondear a dos decimales

try:
    st = speedtest.Speedtest()
    input('Presionar Enter para iniciar la prueba de velocidad')
    
    # Elegir el mejor servidor para asegurar resultados más precisos
    st.get_best_server()
    
    down_speed = bits_to_mbps(st.download())
    up_speed = bits_to_mbps(st.upload())
    ping = st.results.ping

    print(f"Velocidad de descarga: {down_speed} Mbps")
    print(f"Velocidad de subida: {up_speed} Mbps")
    print(f"Ping: {ping} ms")

except Exception as e:
    print("Hubo un error al intentar realizar la prueba de velocidad:", e)