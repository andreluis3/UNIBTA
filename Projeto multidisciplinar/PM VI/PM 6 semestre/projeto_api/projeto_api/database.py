import datetime
import sqlite3

conexao = sqlite3.connect("sensor_teste.db")
cursor = conexao.cursor()

cursor.execute("""
    CREATE TABLE IF NOT EXISTS sinal(
        id_sinal INTEGER PRIMARY KEY,
        valor_db REAL, 
        data_hora DATETIME DEFAULT CURRENT_TIMESTAMP
    );
""")

cursor.execute("""
    CREATE TABLE IF NOT EXISTS maquina(
        id_maquina INTEGER PRIMARY KEY,
        nome_maquina TEXT,
        modelo_maquina TEXT NOT NULL
    );
""")

cursor.execute(""" 
    CREATE TABLE IF NOT EXISTS usuarios (
        id_usuario INTEGER PRIMARY KEY,
        nome_usuario TEXT,
        email TEXT,
        senha TEXT,
        cargo TEXT 
    );
""")

cursor.execute(""" 
    CREATE TABLE IF NOT EXISTS relatorio (
        id_relato INTEGER PRIMARY KEY,
        descricao TEXT,
        data_relato DATETIME DEFAULT CURRENT_TIMESTAMP 
    );
""")

conexao.commit()
print("Banco de dados e tabelas criadas com sucesso")

conexao.close()
