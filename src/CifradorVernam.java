import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class CifradorVernam {
    // Criando uma constante chamada TAMANHO_ARQUIVO, para checagem do tamanho do arquivo antes da operacao
    private static final int TAMANHO_ARQUIVO = 4096;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Exibindo um menu de escolha para o usuário
        System.out.println("1 - CRIPTOGRAFAR");
        System.out.println("2 - DESCRIPTOGRAFAR");
        System.out.print("Escolha uma opção: ");
        int opcao = scanner.nextInt();
        scanner.nextLine(); // Limpar o buffer

        // Validando a escolha do usuario
        if (opcao != 1 && opcao != 2) {
            System.out.println("Opção inválida.");
            return;
        }

        // Solicitando a entrada do arquivo a ser criptografado/descriptografado
        System.out.print("Caminho do arquivo de entrada (4096 bytes): ");
        String entradaPath = scanner.nextLine();

        // Solicitando o arquivo da chave usada para a criptografia
        System.out.print("Caminho do arquivo com a chave (4096 bytes): ");
        String chavePath = scanner.nextLine();

        // Solicitando um arquivo para retornar o resultado da criptografia/descriptografia
        System.out.print("Caminho do arquivo de saída (4096 bytes): ");
        String saidaPath = scanner.nextLine();

        try {
            // Atribuindo os arquivos a arrays do tipo byte
            byte[] entrada = Files.readAllBytes(Path.of(entradaPath));
            byte[] chave = Files.readAllBytes(Path.of(chavePath));

            // Verificando se a chave e o arquivo de entrada possuem 4096 bytes
            if (entrada.length != TAMANHO_ARQUIVO || chave.length != TAMANHO_ARQUIVO) {
                System.out.println("Erro: Todos os arquivos devem ter exatamente 4096 bytes.");
                return;
            }

            //Realizando a operação do XOR 
            byte[] resultado = new byte[TAMANHO_ARQUIVO];
            for (int i = 0; i < TAMANHO_ARQUIVO; i++) {
                resultado[i] = (byte) (entrada[i] ^ chave[i]); // XOR bit a bit
            }

            // Escrevendo o resultado da operação no arquivo de saida
            Files.write(Path.of(saidaPath), resultado);

            // Retornando o sucesso de criptografia/descriptografia ao usuario
            System.out.println((opcao == 1 ? "Criptografia" : "Descriptografia") + " concluída com sucesso!");

        } catch (IOException e) {
            System.out.println("Erro ao ler ou escrever arquivos: " + e.getMessage());
        }

        scanner.close();
    }
}
