#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
            
            return 1;
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //função para checar se o nome votado é o nome de algum dos candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        //se for, um voto é acrescentado ao candidato votado
        if (strcmp(name,  candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    //se não for, o voto é inválido
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //votos
    int votos = 0;
    
    //função para coletar os votos de cada candidato
    for (int i = 0; i < candidate_count; i++)
    {
        //se o candidato tiver mais votos que os de outro candidato,
        if (candidates[i].votes > votos)
        {
            //os votos são contados na variável votos como o que tem mais.
            votos = candidates[i].votes;
        }
    }
    
    //função para ver quem ganhou a eleição
    for (int i = 0; i < candidate_count; i++)
    {
        //se o(s) candidato(s) tiver(em) o mesmo número de votos que o mais votado,
        if (candidates[i].votes == votos)
        {
            //imprime-se o nome de quem
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

