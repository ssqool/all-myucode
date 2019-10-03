
#include <unistd.h>
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *str);
int validation(int argc, char** argv){
	int error_card = -1;
	int size_rank = 1;
    if(argc != 5) {
        write(2, "[card1] [card2] [card3] [card4] [card5]", mx_strlen("[card1] [card2] [card3] [card4] [card5]"));
        return 0;
    }
	
	for(int i = 0; i < argc; i ++) {
		if(mx_strlen(argv[i]) != 2 && mx_strlen(argv[i]) != 3) {
			write(2, "Invalid card: ", mx_strlen("Invalid card: "));
			write(2, argv[i], mx_strlen(argv[i]));
			return 0;
		}
		if (mx_strlen(argv[i]) == 2)
			size_rank = 1;
		else
			size_rank = 2;

		//check suit
        switch (argv[i][size_rank]) {
        	case 'H': break;
        	case 'C': break;
        	case 'S': break; 
        	case 'D': break; 
        	default: {
        		error_card = i;
        		break;
        	}
        }
  
        //check rank
        if (size_rank == 1) {
        switch (argv[i][0]) {
        	case '2': break;
        	case '3': break;
        	case '4': break; 
        	case '5': break; 
        	case '6': break;
        	case '7': break;
        	case '8': break;
        	case '9': break;
        	case 'J': break;
        	case 'Q': break;
        	case 'K': break;
        	case 'A': break;
        	default: {
        		if (error_card == i) {
			        write(2, "Invalid card: ", mx_strlen("Invalid card: "));
			        write(2, argv[i], mx_strlen(argv[i]));
			        return 0;
        		} 
        		else {
			        write(2, "Invalid card rank: ", mx_strlen("Invalid card rank: "));
			        write(2, &argv[i][0], 1);
			        return 0;
        		}
        		    break;
        	    }
            }
            }
            else {
            	if (!(argv[i][0] == '1' && argv[i][1] == '0') && error_card == -1) {
			        write(2, "Invalid card rank: ", mx_strlen("Invalid card rank: "));
			        write(2, argv[i], 2);
			        return 0;            		
            	}
            	else if (!(argv[i][0] == '1' && argv[i][1] == '0') && error_card > 0) {
			        write(2, "Invalid card: ", mx_strlen("Invalid card: "));
			        write(2, argv[i], 3);
			        return 0;            		
            	}
            }
        
            if (error_card > -1) {
        	    write(2, "Invalid card suit: ", mx_strlen("Invalid card suit: "));
			    write(2, &argv[i][size_rank], 1);
			    return 0;	
            }
        
	}
	//check duplicate
	for(int i = 0; i < argc - 1; i++)
	{
		for (int j = i + 1; j < argc; j++)
            if (!mx_strcmp(argv[i], argv[j])) {
			    write(2, "Duplicate cards: ", mx_strlen("Duplicate cards: "));
			    write(2, argv[j], mx_strlen(argv[j]));
        		return 0;            	
            }
	}
	return 1;
}
    
		
	
int main(int argc, char **argv){
   validation(argc - 1, &argv[1]);
   return 0;
}

