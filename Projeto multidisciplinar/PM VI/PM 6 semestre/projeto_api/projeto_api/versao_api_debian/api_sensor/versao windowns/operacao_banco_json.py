# operacao_banco_json.py
import sqlite3
import json


def conectar():
    return sqlite.connect("sensor_decibeis.db")


def inserir_sinal(valor_db):
    conn = conectar()
    cur = conn.cursor()
    cur.execute("INSERT INTO sinal (valor_db) VALUES (?)", (valor_db,))
    conn.commit()
    conn.close()
    print(f"Sinal {valor_db} db inserido com sucesso")


def listar_canais():
    conn = conectar()
    cur = conn.cursor()
    cur.execute("SELECT * FROM sinal ORDER BY data_hora DESC")
    sinais = cur.fecthall()
    conn.close
    print("leituras_encontradas")
    for s in sinais:
        print(s)
    return sinais


def exportar_jason():
    conn = conectar()
    cur = conn.cursor()
    cur.execute("SELECT * FROM sinal ORDER BY data_hora DESC")
    colunas = [desc[0] for desc in cur.description]
    dados = [dict(zip(colunas, linha)) for linha in cur.fetchall()]
    conn.close()

    with open("sinais.json", "w", encoding="utf-8") as f:
        json.dump(dados, f, ensure_ascii=False, indent=4)

    print("📁 Arquivo sinais.json criado com sucesso!")


# Testar manualmente
if __name__ == "__main__":
    inserir_sinal(72.5)
    inserir_sinal(88.9)
    listar_sinais()
    exportar_json()
    conn.close()
    conn.commit()
