#include <iostream>
#include <gccore.h>
#include <wiiuse/wpad.h>
static void *xfb = NULL;
static GXRModeObj *rmode = NULL;
u32 size;
int choice;
int player = 1,game_i;
using namespace std;
void init(){
	VIDEO_Init();
	WPAD_Init();
	rmode = VIDEO_GetPreferredMode(NULL);
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
}

char square[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
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
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void menu(){
	std::cout << "Tic Tac Toe Wii Edition\n\n";
	std::cout << "[A] Play [B] Exit\n";
    
}

void board()
{
    cout << "\n\n\tTic Tac Toe\n\n";

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
void keyboard(){
int currentselection = 1;
	while(true){
		WPAD_ScanPads();
		u32 pressedkey = WPAD_ButtonsDown(0);
		if(pressedkey & WPAD_BUTTON_LEFT){
			if(currentselection <= 1){
				return;
			}
			currentselection--;
			square[currentselection] = 'V';
		}
		if(pressedkey & WPAD_BUTTON_RIGHT){
			if(currentselection >= 9) return;
			currentselection++;
			square[currentselection] = 'V';
		}
		if(pressedkey & WPAD_BUTTON_A){
			break;
		}
	}
}
int main(int argc, char **argv) {
	init();
	char mark;
	bool exit = false;
	bool playing = false;
	printf("\x1b[2;0H");
	while(true) {
		WPAD_ScanPads();
		u32 pressed = WPAD_ButtonsDown(0);
		if ( pressed & WPAD_BUTTON_HOME ) return 0;
		if(pressed & WPAD_BUTTON_B){
			cout << "Do you really want to exit?" << endl << "Press B to exit and A to continue!";
			while(true){
				WPAD_ScanPads();
				u32 pressed = WPAD_ButtonsDown(0);
				if(pressed & WPAD_BUTTON_B){
					game_i = 1;
            		playing = false;
					exit = true;
					break; 
				}
				if(pressed & WPAD_BUTTON_A){
					printf("\x1b[2J");
					playing = true;
					break;
				}
			}
			if(exit) break;
			
			
		}
		if(pressed & WPAD_BUTTON_A){
			printf("\x1b[2J");
			playing = true;
		}
		if(playing){
					do
    {
        board();
        player=(player%2)?1:2;

        keyboard();
		printf("\x1b[2J");
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
            cout<< "Dieser Zug ist nicht moeglich!";

            player--;
            cin.ignore();
            cin.get();
        }
        game_i=checkwin();

        player++;
    }while(game_i==-1);
    board();
    if(game_i==1){
		printf("\x1b[2J");
        cout<<"==>\aSpieler "<<--player<<" hat gewonnen. \n";
		square[0] = 'o';
		square[1] = ' ';
		square[2] = ' ';
		square[3] = ' ';
		square[4] = ' ';
		square[5] = ' ';
		square[6] = ' ';
		square[7] = ' ';
		square[8] = ' ';
		square[9] = ' ';
		menu();
		playing = false;
	}
    else{
		printf("\x1b[2J");
        cout<<"==>\aUnentschieden!\n";
		square[0] = 'o';
		square[1] = ' ';
		square[2] = ' ';
		square[3] = ' ';
		square[4] = ' ';
		square[5] = ' ';
		square[6] = ' ';
		square[7] = ' ';
		square[8] = ' ';
		square[9] = ' ';
		menu();
		playing = false;
	}
		}
		VIDEO_WaitVSync();
	}
    
	return 0;
}
