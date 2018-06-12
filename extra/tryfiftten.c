int main(void)
{
    // define a counter and populate the array
    int c = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
        // fill the tiles in descending order
        board[i][j] = d * d - c;
        c++;
        }
    }
    //make the last tile blank
    board[d-1][d-1] = 99;
    // if there are an odd number of tiles, switch 1 and 2
    if ((d * d)%2 == 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
}