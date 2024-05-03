    #include<iostream>
    #include<stdlib.h>
    #include<time.h>
    #include<cstdlib>
    #include<conio.h>
    #include<windows.h>

    using namespace std;
    class stone
    {
    public :
        #define rounds 4 //pre-defining the total number of rounds for the game
        int userscore = 0;
        int computerscore = 0;
        int machine;
        char user;
        char properInput()//returns only the first character given input as the choice
        {
            char c=getchar();
            if(c>='A'&&c<='Z')
            {
                c = c - 'A' + 'a';//converting the uppercase into lowercase
            }
    while(getchar()!='\n');//ignoring all other characters given input till the user presses enter
    return c;
        }
        char computerChoice()//returns a random choice for the computer for every round
        {
            srand(time(0));//this ensures that random numbers are generated according to the given time, hence providing variety every time
            machine = rand()%3;//this ensures that there are only three possible values: 0,1 and 2
            if(machine==0)
                {
                    return 'r';
                }
            else if(machine==1)
                {
                    return 'p';
                }
            else
                {
                    return 's';
                }
        }
        void userChoice()//takes input the choice of the user for every round
        {
            cout<<"\nInput your choice: ";
            user=properInput();
            while(user!='r' && user!= 'p' && user!='s')
                {
                    cout<<"Invalid choice, re-input your choice: ";
                    user=properInput();
                }
        }
        void printRules()//prints the rules of the game
        {
            cout<<"Rock can beat scissors, paper can beat rock and scissors can beat paper";
            cout<<"\nInput r for rock, the p for paper and s for scissors";
        }
        void game(int currentRound)//recursive function to execute the game for the pre-defined number of rounds
        {
            if(currentRound==rounds)
                {
                    return;//base case which allows complete exit from the function
                }

                fflush(stdin);
            userChoice();
            char computer = computerChoice();
            if(computer=='r')
                {
                    cout<<"Machine played rock. ";
                }
            else if(computer=='p')
                {
        cout<<"Machine played paper. ";
                }
            else
                {
        cout<<"Machine played scissors. ";
                }
                if(user==computer)
                    {
                        cout<<"The round is a draw.\n";
                    }
                else if(user=='r' && computer=='s' || user=='p' && computer=='r' || user=='s' && computer=='p')
                    {
                        cout<<"You win this round.\n";
                        userscore++;
                    }
                else
                    {
                        cout<<"You lose this round.\n";
                        computerscore++;
                    }
                    game(++currentRound);//starting the next round
        }
        void result()//prints the outcome of all the rounds
        {
            cout<<"You scored : "<<userscore<<" and the system scored : "<<computerscore;
            if( userscore==computerscore)
                {
                    cout<<"it is a draw.\n";
                }
            else if (userscore>computerscore)
                {
                    cout<<"you win.\n";
                }
            else
                {
                    cout<<"you lose.\n";
                }
        }

    };
    class guess
    {
        public:
        void guesses()
        {
            cout << "GUESS THE NUMBER...." << '\n';
            cout << "You have to guess a number between 1 and 100. You'll have limited choices based on the level you choose. Good Luck!"<< endl;
            while (true)
                {
            cout << "\nEnter the difficulty level: \n";
            cout << "1 for easy!\t";
            cout << "2 for medium!\t";
            cout << "3 for difficult!\t";
            cout << "0 for ending the game!\n" << endl;
            // select the level of difficulty
            int difficultyChoice;
            cout << "Enter the number: ";
            cin >> difficultyChoice;
            // generating the secret number
            srand(time(0));
            int secretNumber = 1 + (rand() % 100);
            int playerChoice;

            // Difficulty Level:Easy
            if (difficultyChoice == 1) {
                cout << "\nYou have 10 choices for finding the secret number between 1 and 100.";
                int choicesLeft = 10;
                for (int i = 1; i <= 10; i++) {
                    // prompting the player to guess the secret number
                    cout << "\n\nEnter the number: ";
                    cin >> playerChoice;
                    // determining if the playerChoice matches the secret number
                    if (playerChoice == secretNumber)
                        {
                        cout << "Well played! You won, "<< playerChoice<< " is the secret number" << endl;
                        cout << "\t\t\t Thanks for playing...."<< endl;
                        cout << "Play the game again with us!!\n\n"<< endl;
                        break;
                        }
                    else
                    {
                        cout << "Nope, " << playerChoice << " is not the right number\n";
                        if (playerChoice > secretNumber) {
                            cout << "The secret number is smaller than the number you have chosen"<< endl;
                        }
                        else
                        {
                            cout << "The secret number is greater than the number you have chosen"<< endl;
                        }
                        choicesLeft--;
                        cout << choicesLeft << " choices left. "<< endl;
                        if (choicesLeft == 0) {
                            cout << "You could not find the secret number, it was "<< secretNumber<< ", You lose!!\n\n";
                            cout << "Play the game again to win!!!\n\n";
                        }
                    }
                }
            }
            // Difficulty level : Medium
            else if (difficultyChoice == 2) {
                cout << "\nYou have 7 choices for finding the secret number between 1 and 100.";
                int choicesLeft = 7;
                for (int i = 1; i <= 7; i++) {
                        // prompting the player to guess the secret number
                    cout << "\n\nEnter the number: ";
                    cin >> playerChoice;

                    // determining if the playerChoice matches the secret number
                    if (playerChoice == secretNumber) {
                        cout << "Well played! You won, "<< playerChoice << " is the secret number" << endl;
                        cout << "\t\t\t Thanks for playing...."<< endl;
                        cout << "Play the game again with us!!\n\n"<< endl;
                        break;
                    }
                    else {
                        cout << "Nope, " << playerChoice<< " is not the right number\n";
                        if (playerChoice > secretNumber)
                            {
                            cout << "The secret number is smaller than the number you have chosen"<< endl;
                            }
                        else
                            {
                            cout << "The secret number is greater than the number you have chosen"<< endl;
                            }
                        choicesLeft--;
                        cout << choicesLeft << " choices left. "<< endl;
                        if (choicesLeft == 0) {
                            cout << "You couldn't find the secret number, it was "<< secretNumber<< ", You lose!!\n\n";
                            cout << "Play the game again to win!!!\n\n";
                        }
                    }
                }
            }
            // Difficulty level : Medium
            else if (difficultyChoice == 3) {
                cout << "\nYou have 5 choices for finding the secret number between 1 and 100.";
                int choicesLeft = 5;
                for (int i = 1; i <= 5; i++) {
                    // prompting the player to guess the secret number
                    cout << "\n\nEnter the number: ";
                    cin >> playerChoice;
                    // determining if the playerChoice matches the secret number
                    if (playerChoice == secretNumber) {
                        cout << "Well played! You won, "<< playerChoice<< " is the secret number" << endl;
                        cout << "\t\t\t Thanks for playing...."<< endl;
                        cout << "Play the game again with us!!\n\n"<< endl;
                        break;
                    }
                    else {
                        cout << "Nope, " << playerChoice<< " is not the right number\n";
                        if (playerChoice > secretNumber)
                            {
                            cout << "The secret number is smaller than the number you have chosen"<< endl;
                            }
                        else
                        {
                            cout << "The secret number is greater than the number you have chosen"<< endl;
                        }
                        choicesLeft--;
                        cout << choicesLeft << " choices left. "<< endl;
                        if (choicesLeft == 0) {
                            cout << "You couldn't find the secret number, it was "<< secretNumber<< ", You lose!!\n\n";
                            cout << "Play the game again to win!!!\n\n";
                        }
                    }
                }
            }
            // To end the game
            else if (difficultyChoice == 0) {
                    break ;
            }
            else {
                cout << "Wrong choice, Enter valid choice to play the game! (0,1,2,3)"<< endl;
            }
        }
    }
    };
    class quiz
    {
    public:

        struct person
        {
            int marks,random;
        };

        person st;
        void cpp()
        {
            int i=0,arr[10];
            st.marks=0;
            char choice;
            while(i<10)
                {
                    back:
                        st.random=rand()%10;
            for(int j=0;j<10;j++)
                {
                    if(st.random==arr[j])
                    {
                        goto back;
                    }
                }
            arr[i]=st.random;
            switch(st.random)
            {
                case 0:
                    cout<<i+1<<") Who invented C++ ?"<<endl;
                    cout<<"a) Dennis Ritchie"<<endl;
                    cout<<"b) Ken Thompson"<<endl;
                    cout<<"c) Brian Kernighan"<<endl;
                    cout<<"d) Bjarne Stroustrup"<<endl;
                    cout<<"Enter your choice:";
                    choice=getch();
                    cout<<endl<<endl;
                    if(choice=='D'||choice=='d')
                    {
                            cout<<"Your answer is correct"<<endl;
                            st.marks++;
                    }
                    else
                        {
                            cout<<"Your answer is incorrect "<<endl;
                            cout<<"correct answer is d) Bjarne Stroustrup "<<endl;
                        }
                    cout<<endl<<endl;
                    break;
                    case 1:
                        cout<<i+1<<")"<<"What is C++?"<<endl;
                        cout<<"a) C++ is an object oriented programming language"<<endl;
                        cout<<"b) C++ is a procedural programming language"<<endl;
                        cout<<"c) C++ supports both procedural and object oriented programming language"<<endl;
                        cout<<"d) C++ is a functional programming language"<<endl;
                        cout<<"Enter your choice:";
                        choice=getch();
                        cout<<endl<<endl;
                        if(choice=='C'||choice=='c')
                            {
                                cout<<"Your answer is correct"<<endl;
                                st.marks++;
                            }
                        else
                            {
                        cout<<"Your answer is incorrect "<<endl;
                        cout<<"correct answer is c) C++ supports both procedural and object oriented programming language"<<endl;
                        cout<<"Explanation: C++ supports both procedural(step by step instruction) and object oriented programming (using the concept of classes and objects)"<<endl;
                            }
                        cout<<endl<<endl;
                        break;
                        case 2:
                        cout<<i+1<<")Which of the following is the correct syntax of including a user defined header files in C++??"<<endl;
                        cout<<"a) #include [userdefined]"<<endl;
                        cout<<"b) #include “userdefined”"<<endl;
                        cout<<"c) #include <userdefined.h>"<<endl;
                        cout<<"d) #include <userdefined>"<<endl;
                        cout<<"Enter your choice:";
                        choice=getch();
                        cout<<endl<<endl;
                        if(choice=='B'||choice=='b')
                            {
                                cout<<"Your answer is correct"<<endl;
                                st.marks++;
                            }
                        else
                            {
                                cout<<"Your answer is incorrect "<<endl;
                                cout<<"correct answer is b) #include “userdefined”  "<<endl;
                            }
                        cout<<endl<<endl;
                        break;
                        case 3:
                            cout<<i+1<<")Which of the following is used for comments in C++?"<<endl;
                            cout<<"a) /* comment */"<<endl;
                            cout<<"b)  // comment */"<<endl;
                            cout<<"c) // comment"<<endl;
                            cout<<"d) both // comment or /* comment */"<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='D'||choice=='d')
                                {
                                    cout<<"Your answer is correct"<<endl;
                                    st.marks++;
                                }
                            else
                                {
                                    cout<<"Your answer is incorrect "<<endl;
                                    cout<<"correct answer is d) both // comment or /* comment */ "<<endl;
                                }
                                cout<<endl<<endl;
                                break;
                            case 4:
                            cout<<i+1<<")Which of the following is not a type of Constructor in C++"<<endl;
                            cout<<"a)Default constructor" <<endl;
                            cout<<"b) Parameterized constructor"<<endl;
                            cout<<"c)Copy constructor "<<endl;
                            cout<<"d)Friend constructor "<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='D'||choice=='d')
                                {
                                    cout<<"Your answer is correct"<<endl;
                                    st.marks++;
                                }
                            else
                                {
                            cout<<"Your answer is incorrect "<<endl;
                            cout<<"correct answer is d) Friend constructor "<<endl;
                                }
                            cout<<endl<<endl;
                            break;
                            case 5:
                            cout<<i+1<<")Which of the following approach is used by C++?"<<endl;
                            cout<<"a)Left-right" <<endl;
                            cout<<"b) Right-left"<<endl;
                            cout<<"c) Bottom-up"<<endl;
                            cout<<"d)Top-down  "<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='C'||choice=='c')
                                {
                                    cout<<"Your answer is correct"<<endl;
                            st.marks++;
                                }
                            else
                                {
                                    cout<<"Your answer is incorrect "<<endl;
                                    cout<<"correct answer is c) Bottom-up "<<endl;
                                }
                            cout<<endl<<endl;
                            break;
                            case 6:
                            cout<<i+1<<")What is virtual inheritance in C++?"<<endl;
                            cout<<"a) C++ technique to enhance multiple inheritance" <<endl;
                            cout<<"b) C++ technique to ensure that a private member of the base class can be accessed somehow"<<endl;
                            cout<<"c) C++ technique to avoid multiple inheritances of classes"<<endl;
                            cout<<"d)  C++ technique to avoid multiple copies of the base class into children/derived class "<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='D'||choice=='d')
                            {
                                    cout<<"Your answer is correct"<<endl;
                            st.marks++;
                            }
                            else
                            {
                            cout<<"Your answer is incorrect "<<endl;
                            cout<<"correct answer is d)  C++ technique to avoid multiple copies of the base class into children/derived class "<<endl;
                            }
                            cout<<endl<<endl;
                            break;
                            case 7:
                            cout<<i+1<<")What is the difference between delete and delete[] in C++?"<<endl;
                            cout<<"a)delete is syntactically correct but delete[] is wrong and hence will give an error if used in any case" <<endl;
                            cout<<"b) delete is used to delete normal objects whereas delete[] is used to pointer objects"<<endl;
                            cout<<"c)delete is a keyword whereas delete[] is an identifier "<<endl;
                            cout<<"d) elete is used to delete single object whereas delete[] is used to multiple(array/pointer of) objects  "<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='D'||choice=='d')
                                {
                                    cout<<"Your answer is correct"<<endl;
                            st.marks++;
                                }
                            else
                                {
                            cout<<"Your answer is incorrect "<<endl;
                            cout<<"correct answer is d) delete is used to delete single object whereas delete[] is used to multiple(array/pointer of) objects  "<<endl;
                                }
                            cout<<endl<<endl;
                            break;
                            case 8:
                            cout<<i+1<<")Which of the following is correct about this pointer in C++?"<<endl;
                            cout<<"a)this pointer is passed as a hidden argument in all static variables of a class" <<endl;
                            cout<<"b) this pointer is passed as a hidden argument in all the functions of a class"<<endl;
                            cout<<"c)this pointer is passed as a hidden argument in all non-static functions of a class"<<endl;
                            cout<<"d) this pointer is passed as a hidden argument in all static functions of a class "<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='C'||choice=='c')
                                {
                                    cout<<"Your answer is correct"<<endl;
                            st.marks++;
                                }
                            else
                                {
                            cout<<"Your answer is incorrect "<<endl;
                            cout<<"correct answer is c)this pointer is passed as a hidden argument in all non-static functions of a class "<<endl;
                                }
                            cout<<endl<<endl;
                            break;
                            case 9:
                            cout<<i+1<<") Which of the following type is provided by C++ but not C?"<<endl;
                            cout<<"a)double" <<endl;
                            cout<<"b)float"<<endl;
                            cout<<"c)int"<<endl;
                            cout<<"d)bool "<<endl;
                            cout<<"Enter your choice:";
                            choice=getch();
                            cout<<endl<<endl;
                            if(choice=='D'||choice=='d')
                                {
                                    cout<<"Your answer is correct"<<endl;
                            st.marks++;
                                }
                            else
                                {
                            cout<<"Your answer is incorrect "<<endl;
                            cout<<"correct answer is d) bool "<<endl;
                                }
                            cout<<endl<<endl;
                            break;
            }
            i++;
        }
    }
    void result()
    {
        int per=0;
        cout<<"MARKS :"<<st.marks<<" out of 10"<<endl;
        per=100*st.marks/10;
        if(per>=30)
            {
                cout<<"STATUS : PASS"<<endl;
            }
        else{
                cout<<"STATUS : FAIL"<<endl;
            }
    }
    };
    class tic{
    public:
        int player = 1,i,choice;
        char mark;
    char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
    int checkwin()
    {

        if (square[1] == square[2] && square[2] == square[3])
            return 1;
        else if (square[4] == square[5] && square[5] == square[6])
            return 1;
        else if (square[7] == square[8] && square[8] == square[9])
            return 1;
        else if (square[1] == square[4] && square[4] == square[7])
            return 1;
        else if (square[2] == square[5] && square[5] == square[8])
            return 1;
        else if (square[3] == square[6] && square[6] == square[9])
            return 1;
        else if (square[1] == square[5] && square[5] == square[9])
            return 1;
        else if (square[3] == square[5] && square[5] == square[7])
            return 1;
        else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6'&& square[7] != '7' && square[8] != '8' && square[9] != '9')
            return 0;
        else
            return -1;
    }
    void board()
    {
        system("cls");
        cout << "TIC TAC TOE...."<< '\n';
        cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
        cout << endl;
        cout << "     |     |     " << endl;
        cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
        cout << "     |     |     " << endl << endl;
    }
    void mains()
    {
        do
        {
            board();
            player=(player%2)?1:2;
            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;
            mark=(player == 1) ? 'X' : 'O';
            if (choice == 1 && square[1] == '1')
                square[1] = mark;
            else if (choice == 2 && square[2] == '2')
                square[2] = mark;
            else if (choice == 3 && square[3] == '3')
                square[3] = mark;
            else if (choice == 4 && square[4] == '4')
                square[4] = mark;
            else if (choice == 5 && square[5] == '5')
                square[5] = mark;
            else if (choice == 6 && square[6] == '6')
                square[6] = mark;
            else if (choice == 7 && square[7] == '7')
                square[7] = mark;
            else if (choice == 8 && square[8] == '8')
                square[8] = mark;
            else if (choice == 9 && square[9] == '9')
                square[9] = mark;
            else
            {
                cout<<"Invalid move ";

                player--;
                cin.ignore();
                cin.get();
            }
            i=checkwin();
            player++;
        }
        while(i==-1);
        board();
        if(i==1)
            cout<<"==>\aPlayer "<<--player<<" win ";
        else
            cout<<"==>\aGame draw";
        cin.ignore();
        cin.get();
    }
    };

    int main()
    {
        system ("color c2");
        system("setfont calibri");
        int x;
        stone obj1;
        guess obj2;
        quiz obj3;
        tic obj4;
        char a;
        cout<<endl<<endl;
        cout << "....GAME HOUSE...." << '\n';

        cout<<"PLAY A GAME"<<endl;
        cout<<"GAME 1 STONE PAPER SCISSORS "<<endl;
        cout<<"GAME 2 GUESSING GAME"<<endl;
        cout<<"GAME 3 QUIZ GAME"<<endl;
        cout<<"GAME 4 TIC TAC TOE"<<endl;
        cout<<"Enter any key to begin ";
        cin>>a;
    system("CLS");
            char p;
            do
            {
            cout << "STONE PAPER SCISSORS...." << '\n';
            
            obj1.printRules();
            obj1.game(0);
            obj1.result();
            cout<<"Press 'y' to Play again!! or any key to terminate"<<endl;
            p=getch();
            cout<<endl<<endl;
            }
            while(p=='y'||p=='Y');
            system("CLS");
            char s;
            do{
                obj2.guesses();
                p=getch();
            }
            while(s=='y'||s=='Y');

        char press,select;
        do{
            system("CLS");
            cout << "QUIZ GAME..." << '\n';
            cout<<endl<<endl;

            cout<<"\t----------------INSTRUCTIONS------------------------"<<endl;
            cout<<"\t\tMarks less than 30% will be fail"<<endl;
            cout<<"\t\tEach correct Question will add 1 marks"<<endl;
            cout<<"\t\tThere is no negative marking in the Game"<<endl<<endl<<endl;
            cout<<"\t\t\tALL THE BEST!!!! "<<endl;
            cout<<"Press 1 to start Quiz"<<endl;
            select=getch();
            system("CLS");
            switch(select)
            {
            case '1':
                cout<<"\t\tC+++ Quiz "<<endl;
                obj3.cpp();
                system("CLS");
                cout<<"-----------------------------------"<<endl;
                cout<<"\t\t Quiz result"<<endl;
                cout<<"------------------------------------"<<endl;
                obj3.result();
                break;
            default :
                cout<<"You entered a wrong key";
            }
            cout<<"Press 'y' to Play again!! or any key to terminate"<<endl;
            press=getch();
        }
        while(press=='y'||press=='Y');

            tic obj;
            obj.checkwin();
            obj.board();
            obj.mains();
            cout<<"******************************************************************************"<<endl;
            cout << "THANK YOU !" << '\n';                                                                                                                                                                                   

        };
