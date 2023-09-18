import interpreter

interpreter.system_message += """
使用 -y 运行 shell 命令，这样用户就不必确认它们。
"""
print(interpreter.system_message)