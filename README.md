# Grupo: Mãos Solidárias
Apresentação A3 - Modelos, métodos e técnicas da engenharia de software 


# Software: Mãos Solidárias 🤝
<img src= "https://private-user-images.githubusercontent.com/146378274/337921141-0995bb3b-3600-4d46-b1e5-1ca8220c0c4c.jpeg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTc4Njc0OTUsIm5iZiI6MTcxNzg2NzE5NSwicGF0aCI6Ii8xNDYzNzgyNzQvMzM3OTIxMTQxLTA5OTViYjNiLTM2MDAtNGQ0Ni1iMWU1LTFjYTgyMjBjMGM0Yy5qcGVnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQVZDT0RZTFNBNTNQUUs0WkElMkYyMDI0MDYwOCUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyNDA2MDhUMTcxOTU1WiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9ZjA0ZGNhNzE5YjJlNmJmMjdlMWEyMTJiNDRmNDI4NDRmMWM5M2MwYmZmYzQwNmRhOGI2OWVmNDNkYzYyMjA0NCZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QmYWN0b3JfaWQ9MCZrZXlfaWQ9MCZyZXBvX2lkPTAifQ.cfKJmjQ4jHmiSEiFaN7_d7w1QZocLwigx8koRXvuaOg" width="480"/>

# Sobre o Projeto

O software "Mãos Solidárias" visa auxiliar na organização e gestão de esforços durante as enchentes no Rio Grande do Sul. A aplicação permite a realização de cadastro de desabrigados, doações, voluntários e permite selecionar hierarquia na classe de voluntários, selecionando assim gestor geral do aplicativo. A aplicação possibilita melhor comunicação e gestão dentro dos abrigos.


# Índice/Sumário

* [Sobre](#sobre-o-projeto)
* [Sumário](#índice/sumário)
* [Descrição das Funcionalidades](#funcionalidades-do-sistema)
* [Requisitos Funcionais](#requisitos-funcionais)
* [Requisitos Não Funcionais](#requisitos-não-funcionais)
* [Tecnologias Usadas](#tecnologias-usadas)

# Funcionalidades do Sistema

- **Funcionalidades Principais:**

**1.** Cadastro de Voluntários: Permite que indivíduos se registrem como voluntários,
incluindo suas habilidades e disponibilidade.

**2.** Cadastro de Abrigos: Gestores de abrigos podem registrar e atualizar informações
sobre a capacidade.

**3.** Solicitação de Ajuda: Pessoas afetadas pelas enchentes podem solicitar ajuda
através da plataforma, especificando suas necessidades e localização.

**4.** Controle de Estoque de Doações: Sistema para gerenciar as doações recebidas,
categorizando itens como roupa, itens de higiene, alimentos, roupa de cama,
calçados, etc.

**5.** Gestão de Usuários:

- a. Voluntários: Registro e gerenciamento de voluntários.

- b. Gestores de Abrigos: Controle de doações, gestão de equipes e abrigos.

- c. Gestor Administrador: Adição e gerenciamento de gestores, controle de
    estoque de doações e visualização de relatórios detalhados.


# Requisitos Funcionais 

- **RF1 - Cadastro de Voluntários:**

O sistema deve permitir que usuários se cadastrem como voluntários fornecendo nome, contato, habilidades e disponibilidade. Além disso, o sistema deve permitir a edição das informações de cadastro de voluntários.



- **RF2 - Menu Voluntário:**

O sistema deve exibir uma lista de abrigos disponíveis para se voluntariar. Voluntários têm a opção de se registrar para atuar em um local específico. Além disso, é possível fazer doações, registrando o tipo e a quantidade de itens doados.

- **RF3 - Cadastro de Abrigos:**

O sistema permite que gestores de abrigos registrem informações sobre os abrigos, incluindo nome, localização, capacidade e informações de contato, além de possibilitar a atualização desses dados e exibir uma lista de abrigos registrados com detalhes de capacidade.

- **RF4 - Menu Gestor:**

O sistema deve possibilitar o monitoramento das doações recebidas, fazendo o registro do tipo e da quantidade de itens. Deve também facilitar a administração das equipes de voluntários, permitindo a visualização e a distribuição de voluntários para diversas tarefas. Além disso,deve possibilitar o registro de novos abrigos e a atualização de informações já existentes. Por fim, deve permitir o gerenciamento do estoque de itens doados, organizando os itens por categoria (como roupas, itens de higiene, alimentos, etc.)

- **RF5 - Solicitação de Ajuda:**

O sistema permite que pessoas necessitadas se cadastrem, fornecendo nome, contato, localização e tipo de ajuda necessária. Além disso, o sistema possibilita a edição das solicitações de ajuda e exibe uma lista com solicitações e detalhes fornecidos pelos solicitantes.

- **RF6 - Gestor Administrador:**

O sistema deve possibilitar ao administrador a inclusão e o controle de outros gestores. Este mesmo administrador deve ter a capacidade de inserir e administrar itens doados no estoque. Além disso, o sistema deve oferecer a opção para o administrador delegar a responsabilidade de controle de estoque a outros gestores. Por fim, deve permitir ao administrador a visualização de relatórios minuciosos sobre a situação das doações e do estoque.

- **RF7 - Controle de Estoque:**

O sistema possibilita o registro de doações em diferentes categorias (roupa, itens de higiene, alimentos, roupa de cama, calçados, etc.), permite a atualização do estoque conforme os itens são distribuídos ou recebidos e exibe o status atual do estoque, incluindo as quantidades disponíveis de cada item.

# Requisitos Não Funcionais

- **RNF1 Desempenho:**
 
O sistema deve ter a capacidade de acomodar até 5.000 usuários ao mesmo tempo sem comprometer significativamente o desempenho. As tarefas de leitura e escrita no banco de dados devem ser finalizadas em um período inferior a 2 segundos.

- **RNF2 Usabilidade:**

O sistema deve seguir as diretrizes de acessibilidade para garantir que
pessoas com deficiência possam utilizá-lo.

- **RNF3 Manutenibilidade:**

Para facilitar a manutenção e futuras atualizações, o código do sistema deve ser devidamente documentado. Além disso, o sistema deve aderir a padrões de codificação consistentes e seguir as melhores práticas de engenharia de software


# Tecnologias Usadas

- [Replit](https://replit.com/)
- [Visual Studio Code](https://vscode.dev/)
- [Xtensio](https://xtensio.com/)
- [Figma](https://www.figma.com/) 



# Slides com Link do Vídeo de Apresentação

POR AQUI O ARQUIVO PDF E LINK DO VÍDEO.
