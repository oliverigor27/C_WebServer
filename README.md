**Webserver Simples em C**

Este é um projeto de webserver simples em C, desenvolvido com o propósito de estudar como um servidor aceita conexões TCP. Atualmente, o servidor está em fase inicial de desenvolvimento e não está funcionando corretamente, porém, serve como um esqueleto básico que passará por melhorias e refinamentos.

### Funcionalidades Atuais
- Aceita conexões TCP simples
- Responde com mensagens básicas

### Funcionalidades Planejadas
- Suporte para múltiplas conexões simultâneas
- Servir páginas HTML estáticas
- Manipulação de solicitações GET e POST
- Melhorias de desempenho e segurança

### Como Usar
1. **Pré-requisitos**
   - Compilador C (como gcc)
   - Ambiente Linux/Unix

2. **Compilação**
   ```bash
   gcc -o webserver webserver.c
   ```

3. **Execução**
   ```bash
   ./webserver
   ```

4. **Acessando o Servidor**
   - Abra um navegador web
   - Acesse `http://localhost:8080/` para ver a resposta padrão do servidor

### Estrutura do Código
- `webserver.c`: Contém o código-fonte principal do servidor


### Notas
Este servidor foi criado para fins educacionais e de aprendizado. Não é adequado para uso em produção sem uma extensa revisão e melhorias de segurança.


