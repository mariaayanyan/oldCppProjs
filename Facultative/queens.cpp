#include <iostream>
#include <vector>

class ChessBoard
{
    public:

    ChessBoard(int n = 8): n(n),
    board(n, std::vector<char>(n, '.')),
    rows(n, false),
    cols(n, false),
    primary(2*n - 1, false), //i+j
    secondary(2*n - 1, false) //i-j+n-1      
    {
        
    }

    void solve()
    {
        solve(0, 0, 0);   
    }

    private:

    void print()
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cout << board[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    void solve(int i, int j, int count) 
    {
        if(count == n)
        {
            print();
            return;
        }

        if(i == n)
        {
            return;
        }

        int next_i = i + (j+1)/n;
        int next_j = (j+1)%n;

        if(board[i][j] == '.' && !rows[i] && !cols[j] && !primary[i+j] && !secondary[i-j+n-1])
        {
            rows[i] = cols[j] = primary[i+j] = secondary[i-j+n-1] = true;
            board[i][j] = 'Q';
            solve(next_i, next_j, count+1);
            rows[i] = cols[j] = primary[i+j] = secondary[i-j+n-1] = false;
            board[i][j] = '.';
        }
        solve(next_i, next_j, count);
    }

    int n;
    std::vector<std::vector<char> > board; 
    std::vector<char> rows, cols, primary, secondary;
       
};

int main()
{
    int n;
    std::cin >> n;
    ChessBoard chess(n);
    chess.solve();
}