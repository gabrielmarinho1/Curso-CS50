#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //fun????o que ir?? validar o voto e atualizar o rank dos candidatos.
    for (int i = 0; i < candidate_count; i++)
    {
        //se o nome votado for igual a algum os candidatos,
        if (strcmp(name, candidates[i].name) == 0)
        {
            //o candidado ?? adicionado no rank do eleitor.
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //fun????o para ver o voto preferencial de cada eleitor
    for (int i = 0; i < voter_count; i++)
    {
        //vari??vel que ter?? o "endere??o" do voto
        int l;
        
        //fun????o que ver?? qual candidado foi votado como preferencial
        for (int j = 0; j < candidate_count; j++)
        {
            //l ganha o endere??o do voto
            l = preferences[i][j];
            
            //se o candidato votado n??o estiver eliminado
            if (!candidates[l].eliminated)
            {
                //o candidato ganha um voto
                candidates[l].votes++;
                
                //o loop encerra
                break;
            }
            
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //fun????o que ver?? se algum dos candidatos ganhou
    for (int j = 0; j < candidate_count; j++)
    {
        //se o candidato tiver mais que a metade dos votos, ele venceu
        if (candidates[j].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = candidates[0].votes;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    //fun????o que ver?? os votos de cada candidato
    for (int i = 0; i < candidate_count; i++)
    {
        //se o candidato n??o estiver eliminado
        if (!candidates[i].eliminated)
        {
            //se a quantidade de votos do candidato n??o for igual ao m??nimo, ent??o n??o ?? empate
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    //fun????o que evr?? a quantidade de votos de cada candidato
    for (int i = 0; i < candidate_count; i++)
    {
        //se o candidato n??o estiver eliminado
        if (!candidates[i].eliminated)
        {
            //se o n??mero de votos do candidato for igual ao n??mero m??nimo de votos, ele ?? eliminado
            if (candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
    // TODO
    return;
}
