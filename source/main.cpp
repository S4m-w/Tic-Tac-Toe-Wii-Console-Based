#include <iostream>
#include <time.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
static void *xfb = NULL;
static GXRModeObj *rmode = NULL;
u32 size;
int choice;
std::string square[10] = {"NONE", " ", " ", " ", " ", " ", " ", " ", " ", " "}; 
int player = 1,game_i;
int currentselection = 1;
int tie = 0;
bool onetime = true;

std::string bak[10] {square[0],square[1],square[2],square[3],square[4],square[5],square[6],square[7],square[8],square[9]};
void board()
{
	printf("\x1b[2J");
    std::cout << "\n\n\tTic Tac Toe\n\n";

    std::cout << std::endl;

    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << std::endl;
				
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << std::endl;

    std::cout << "     |     |     " << std::endl << std::endl;
}
void reset()  {
	bak[1] = " ";
			bak[2] = " ";
			bak[3] = " ";
			bak[4] = " ";
			bak[5] = " ";
			bak[6] = " ";
			bak[7] = " ";
			bak[8] = " ";
			bak[9] = " ";
			square[1] = " ";
			square[2] = " ";
			square[3] = " ";
			square[4] = " ";
			square[5] = " ";
			square[6] = " ";
			square[7] = " ";
			square[8] = " ";
			square[9] = " ";
			board();
}

void restore(std::string bak[10]){
	square[0] = bak[0];
	square[1] = bak[1];
	square[2] = bak[2];
	square[3] = bak[3];
	square[4] = bak[4];
	square[5] = bak[5];
	square[6] = bak[6];
	square[7] = bak[7];
	square[8] = bak[8];
	square[9] = bak[9];
}
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
void place(int selection){
	if(player == 1){
		square[selection] = "X";
		bak[selection] = "X";
		player++;
		tie++;
		
		
		
	}else if(player == 2){
		square[selection] = "O";			

		bak[selection] = "O";
		player--;
		tie++;
	}
	}


void menu(){
	std::cout << "Tic Tac Toe Wii Edition\n\n";
	std::cout << "[A] Play [HOME] Exit\n"; 
}



void keyboard(){
	int currentselection = 1;
onetime = true;
	

	while(true){
		WPAD_ScanPads();
        u32 pressedkey = WPAD_ButtonsDown(0);
		if(bak[1] == "X" && bak[2] == "X" && bak[3] == "X"){
				if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
        if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
			reset();
currentselection = 1;
onetime = true;
continue;
		
			onetime = true;
			continue;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
		
		}
	if(bak[1] == "X" && bak[4] == "X" && bak[7] == "X" ){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
onetime = true;

		
		}
	}
    if(bak[1] == "X" && bak[5] == "X" && bak[9] == "X"){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
		
continue;
		
		}
	}
	if(bak[2] == "X" && bak[5] == "X" && bak[8] == "X"){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
	else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[3] == "X" && bak[6] == "X" && bak[9] == "X"){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[3] == "X" && bak[5] == "X" && bak[7] == "X"){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[4] == "X" && bak[5] == "X" && bak[6] == "X"){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
	else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[7] == "X" && bak[8] == "X" && bak[9] == "X"){
		if(onetime){
	std::cout << "Player 1 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	} 
	if(bak[1] == "O" && bak[2] == "O" && bak[3] == "O"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
		}
	if(bak[1] == "O" && bak[4] == "O" && bak[7] == "O" ){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
    if(bak[1] == "O" && bak[5] == "O" && bak[9] == "O"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[2] == "O" && bak[5] == "O" && bak[8] == "O"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[3] == "O" && bak[6] == "O" && bak[9] == "O"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[3] == "O" && bak[5] == "O" && bak[7] == "O"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[4] == "O" && bak[5] == "O" && bak[6] == "Ocontinue;"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
continue;
		
		}
	}
	if(bak[7] == "O" && bak[8] == "O" && bak[9] == "O"){
		if(onetime){
	std::cout << "Player 2 has won! Press B to quit and the a key to play again!";
	onetime = false;
}
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey & WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
            onetime = true;
		continue;
		}
	}
	if(tie == 9){
		if(onetime){
std::cout << "Tie! Press B to quit and the a key to play again!";
onetime = false;
		}
		
		if(pressedkey & WPAD_BUTTON_B){
			exit(0);
		}
		else if(pressedkey == WPAD_BUTTON_A){
			tie = 0;
			player = 1;
			reset();
currentselection = 1;
onetime = true;
onetime = true;
continue;
		
		}
	}
		
	
		if(pressedkey & WPAD_BUTTON_LEFT){
			if(square[currentselection] != "X" || square[currentselection] != "O"){
				restore(bak);
			}
			if(currentselection <= 1){
				square[1] = 'I';
				continue;
			}
			currentselection--;
			square[currentselection] = 'I';
			board();
		}
		if(pressedkey & WPAD_BUTTON_RIGHT){
			if(square[currentselection] != "X" && square[currentselection] != "O"){
				restore(bak);
			}
			if(square[9] == "V"){
				square[currentselection][9];				

			}

			if(currentselection >= 9) {
square[9] = 'I';
continue;
			}
			currentselection++;
			square[currentselection] = 'I';
			board();
		}
		if(pressedkey & WPAD_BUTTON_A){
			if(bak[currentselection] != " "){
				printf("\x1b[2J");
				std::cout << "This square is already used!";
				board();
				continue;
			}
		
			else{
			    place(currentselection);
				board();
			}	
		}
	}
}
int main(int argc, char **argv) {
	init();printf("\x1b[2J");
		board();

	while(true) {
		WPAD_ScanPads();
		u32 pressed = WPAD_ButtonsDown(0);
		if ( pressed & WPAD_BUTTON_HOME ) return 0;
		board();
		keyboard();
		VIDEO_WaitVSync();
	}
	return 0;
}
