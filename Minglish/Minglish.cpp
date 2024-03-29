#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max_len 25
#define dict_capa 5495
#define main_interf 0
#define alpha_order_interf 1
#define freq_order_interf 2
#define rand_order_interf 3
#define test_main_interf 4
#define view_dict_interf 5
#define show_heart_interf 6
#define delete_star 7
#define main_exit 8
#define new_alpha_interf 11
#define con_alpha_interf 12
#define alpha_retr_main 13
#define alpha_exit 14
#define new_freq_interf 21
#define con_freq_interf 22
#define freq_retr_main 23
#define freq_exit 24
#define text_freqhh_interf 41
#define text_freqh_interf 42
#define text_rand_interf 43
#define text_retr_main 44
#define text_exit 45
#define view_dict_freq_interf 51
#define view_dict_abc_interf 52
#define view_dict_star_interf 53
#define view_dict_back 54
#define view_dict_exit 55


int appr_interf[] = {
	0,
	1, 11, 12, 13, 14,
	2, 21, 22, 23, 24,
	3,
	4, 41, 42, 43, 44, 45,
	5, 51, 52, 53, 54, 55,
	6,
	7,
	8
};

int now_interf = main_interf;

int in_appr_interf(int interf){
	for (int i = 0; i < sizeof(appr_interf) / sizeof(appr_interf[0]); i++){
		if (interf == appr_interf[i]){
			return 1;
		}
	}
	return 0;	
}

typedef struct {
    char word[dict_capa][max_len];
    char meaning[dict_capa][max_len * 2];
    int star[dict_capa];
} Dict;

int show_main_interf(){
	now_interf = main_interf;
	system("cls");
	printf("************************************************************************\n");
	printf("************************* \033[36mWelcome to Minglish!\033[0m *************************\n");
	printf("************************************************************************\n");
	printf("***************** \033[36mWhat do you want? Input the number.\033[0m ******************\n");
	printf("************************************************************************\n");
	printf("\n");
	printf("                     \033[36m1.Learn in alphabetical order.\033[0m\n");
	printf("                     \033[36m2.Learn in exam frequency order.\033[0m\n");
	printf("                     \033[36m3.Learn randomly.\033[0m\n");
	printf("                     \033[36m4.Do word test.\033[0m\n");
	printf("                     \033[36m5.View dictionary.\033[0m\n");
	printf("                     \033[36m6.Show heart.\033[0m\n");
	printf("                     \033[36m7.Delete all stars(*).\033[0m\n");
	printf("                     \033[36m8.Exit.\033[0m\n");
	return 1;
}

int back_2_main_interf(){
	now_interf = main_interf;
	return show_main_interf();
}

int show_alpha_order_interf(){
	now_interf = alpha_order_interf;
	system("cls");
	printf("************************************************************************\n");
	printf("**************** \033[36mStart learning in alphabetical order.\033[0m *****************\n");
	printf("************************************************************************\n");
	printf("***************** \033[36mWhat do you want? Input the number.\033[0m ******************\n");
	printf("************************************************************************\n");
	printf("\n");
	printf("                     \033[36m1.Start learning from the first word.\033[0m\n");
	printf("                     \033[36m2.Continue learning at the location you leave.\033[0m\n");
	printf("                     \033[36m3.Back.\033[0m\n");
	printf("                     \033[36m4.Exit.\033[0m\n");
	return 1;
}

int show_freq_order_interf(){
	now_interf = freq_order_interf;
	system("cls");
	printf("************************************************************************\n");
	printf("***************** \033[36mStart learning in frequency order.\033[0m *******************\n");
	printf("************************************************************************\n");
	printf("***************** \033[36mWhat do you want? Input the number.\033[0m ******************\n");
	printf("************************************************************************\n");
	printf("\n");
	printf("                     \033[36m1.Start learning from the first word.\033[0m\n");
	printf("                     \033[36m2.Continue learning at the location you leave.\033[0m\n");
	printf("                     \033[36m3.Back.\033[0m\n");
	printf("                     \033[36m4.Exit.\033[0m\n");
	return 1;
}

int show_test_main_interf(){
	now_interf = test_main_interf;
	system("cls");
	printf("************************************************************************\n");
	printf("************************** \033[36mReady for a text.\033[0m ***************************\n");
	printf("************************************************************************\n");
	printf("***************** \033[36mWhat do you want? Input the number.\033[0m ******************\n");
	printf("************************************************************************\n");
	printf("\n");
	printf("                     \033[36m1.Start a text within very high frequency words.\033[0m\n");
	printf("                     \033[36m2.Start a text within high frequency words.\033[0m\n");
	printf("                     \033[36m3.Start a text within all words.\033[0m\n");
	printf("                     \033[36m4.Back.\033[0m\n");
	printf("                     \033[36m5.Exit.\033[0m\n");
	return 1;
}

int show_learn_main_interf(Dict* dict, int loc){
	system("cls");
	printf("Do you know the meaning of the following word? Input a number to continue.\n\n");
	printf("1.Last word.\n");
	printf("2.Show the meaning.\n");
	printf("3.Next word.\n");
	printf("4.Star this word.\n");
	printf("5.Stop learning and back.\n");
	printf("6.Stop learning and exit.\n\n");
	if (dict->star[loc]){
		printf("%s *: ", dict->word[loc]);
	} else{
		printf("%s: ", dict->word[loc]);
	}
	return 1;
}

int show_dict_main_interf(){
	now_interf = view_dict_interf;
	system("cls");
	printf("What kind of dictionary do you want to view?\n\n");
	printf("1.Dictionary in frequency order.\n");
	printf("2.Dictionary in alphabetic order.\n");
	printf("3.Only started words.\n");
	printf("4.Back.\n");
	printf("5.Exit.\n");
	return 1;
}

int learn(Dict* dict, Dict* dict_another, int is_new){
	int is_freq;
	if (dict->word[0][0] == 'a'){
		is_freq = 0;
	} else{
		is_freq = 1;
	}
	int first = 0;
	int another_loc;
	int freq_first = 0;
	int abc_first = 0;
	FILE* fp, *fp_star;
	if ((fp = fopen("history.txt", "r+")) != NULL){
		char buffer[100]; 
		char delims[] = ","; 
		char* line, *token;
		fseek(fp, 0, SEEK_SET);
		if((line = fgets(buffer, sizeof(buffer), fp)) != NULL){
			if ((token = strtok(line, delims)) != NULL){
				for (int i = 0; i < strlen(token); i++){
					if ('0' <= token[i] && token[i] <= '9'){
						freq_first = freq_first * 10 + (token[i] - '0');
					}
				}
				if ((token = strtok(NULL, delims)) != NULL){
					for (int i = 0; i < strlen(token); i++){
						if ('0' <= token[i] && token[i] <= '9'){
							abc_first = abc_first * 10 + (token[i] - '0');
						}
					}
				}	
			}
		}
		first = (is_freq ? freq_first : abc_first) * !is_new;
		first = (0 <= first  && first < dict_capa) ? first : 0; 
		char key[100];
		int num;
		char buf[10];
		while (1){
			if (show_learn_main_interf(dict, first)){
				int input_ok = 1;
		    	while (1){
		    		scanf("%s", key);
		    		num = key[0] - '0';
					switch (num){
						case 1:
							if (first){
								first--;
							}
							break;
						case 2:
							printf("%s\n\n", dict->meaning[first]);
							printf("Input any number to continue.");
							scanf("%s", buf);
							break;
						case 3:
							if (first < dict_capa - 1 && dict->word[first][0] != '\0' && dict->word[first][0] != '\n'){
								first++;
							}
							break;
						case 4:
							for (int i = 0; i < dict_capa; i++){
								if (!strcmp(dict->word[first], dict_another->word[i])){
									another_loc = i;
									break;
								}
							}
							if ((fp_star = fopen("star.txt", "a+")) != NULL){
								fseek(fp_star, 0, SEEK_END);
								fprintf(fp_star, "%d,%d\n", is_freq, first);
								fprintf(fp_star, "%d,%d\n", !is_freq, another_loc);
								fclose(fp_star);
								fp_star = NULL;
							}
							dict->star[first] = 1;
							dict_another->star[another_loc] = 1;
							break;
						case 5:
							fseek(fp, 0, SEEK_SET);
							fprintf(fp, "                                       ");
							fseek(fp, 0, SEEK_SET);
							if (is_freq){
								fprintf(fp, "%d,%d", first, abc_first);
								now_interf = freq_order_interf;
								fclose(fp);
								fp = NULL;
								return show_freq_order_interf();
							} else{
								fprintf(fp, "%d,%d", freq_first, first);
								fclose(fp);
								fp = NULL;
								return show_alpha_order_interf();
							}
						case 6:
							fseek(fp, 0, SEEK_SET);
							fprintf(fp, "                             ");
							fseek(fp, 0, SEEK_SET);
							if (is_freq){
								fprintf(fp, "%d,%d\n", first, abc_first);
								fclose(fp);
								fp = NULL;
								return 0;
							} else{
								fprintf(fp, "%d,%d\n", freq_first, first);
								fclose(fp);
								fp = NULL;
								return 0;
							}
						default:
							printf("Your input is ineffective, please input again!\n");
							input_ok = 0;
							break;
					}	
					if (input_ok){
						break;
					}
				}
			}
		}
		fclose(fp);
		fp = NULL;
	}
	return 1;
}

int rand_learn(Dict* dict_abc, Dict* dict_freq){
	int loc = rand() % dict_capa;
	int last_loc = loc;
	int another_loc;
	FILE* fp_star;
	char key[10];
	char buf[100];
	int num;
	int input_ok;
	while (1){
		if (show_learn_main_interf(dict_abc, loc)){
			while (1){
				input_ok = 1;
		    	scanf("%s", key);
		    	num = key[0] - '0';
				switch (num){
					case 1:
						loc = last_loc;
						break;
					case 2:
						printf("%s\n\n", dict_abc->meaning[loc]);
						printf("Input any number to continue.");
						scanf("%s", buf);
						break;
					case 3:
						last_loc = loc;
						while (1){
							loc = rand() % dict_capa;
							if (dict_abc->word[loc][0] != '\0' && dict_abc->word[loc][0] != '\n'){
								break;
							}
						}
						break;
					case 4:
						for (int i = 0; i < dict_capa; i++){
							if (!strcmp(dict_freq->word[i], dict_abc->word[loc])){
								another_loc = i;
								break;
							}
						}
						if ((fp_star = fopen("star.txt", "a+")) != NULL){
							fseek(fp_star, 0, SEEK_END);
							fprintf(fp_star, "%d,%d\n", 0, loc);
							fprintf(fp_star, "%d,%d\n", 1, another_loc);
							fclose(fp_star);
							fp_star = NULL;
						}
						dict_abc->star[loc] = 1;
						dict_freq->star[another_loc] = 1;
						break;
					case 5:
						return show_main_interf();
					case 6:
						return 0;
					default:
						printf("Your input is ineffective, please input again!\n");
						input_ok = 0;
						break;
				}	
				if (input_ok){
					break;
				}
			}
		}
	}
	return 1;
}

int show_testing_interf(Dict* dict, int num, int did){
	system("cls");
	printf("You are in a test, please be careful, good luck to you!\n\n");
	printf("1.Last word.\n");
	printf("2.Show the meaning.\n");
	printf("3.Next word.\n");
	printf("4.Star this word.\n");
	printf("5.Stop testing and back.\n");
	printf("6.Stop testing and exit.\n\n");
	if (dict->star[num]){
		if (did){
			printf("%s *   (did): ", dict->word[num]);	
		} else{
			printf("%s *   (not did): ", dict->word[num]);
		}
	} else{
		if (did){
			printf("%s   (did): ", dict->word[num]);
		} else{
			printf("%s   (not did): ", dict->word[num]);
		}
	}
}

int test(Dict* dict_freq, Dict* dict_abc, int total_num){
	FILE* fp_star;
	char key[100];
	char buf[100];
	int tested_num;
	system("cls");
	printf("How many words do you want to test?\n");
	while (1){
		tested_num = 0;
		scanf("%s", key);
		for (int i = 0; i < strlen(key); i++){
			if (key[i] >= '0' && key[i] <= '9'){
				tested_num = tested_num * 10 + (key[i] - '0');
			}
		}
		if (tested_num > 0 && tested_num <= total_num){
			break;
		} else{
			printf("Your input is ineffective, please input again!\n");
		}
	}
	int index_list[tested_num];
	int i = 0;
	int index;
	while (1){
		index = rand() % total_num;
		if (dict_freq->word[index][0] != '\0' && dict_freq->word[index][0] != '\n'){
			index_list[i] = index;
			i++;
		}
		if (i >= tested_num){
			break;
		}
	}
	i = 0;
	int loc;
	int input_ok, input_ok_right;
	int num;
	int is_right;
	int rights_and_wrongs[tested_num];
	int did[tested_num] = {0};
	int did_num = 0;
	while (1){
		index = index_list[i];
		if (show_testing_interf(dict_freq, index, did[i])){
			while (1){
				input_ok = 1;
		    	scanf("%s", key);
		    	num = key[0] - '0';
				switch (num){
					case 1:
						if (i){
							i--;
						}
						break;
					case 2:
						printf("%s\n\n", dict_freq->meaning[index]);
						printf("Input any number to continue.");
						scanf("%s", buf);
						break;
					case 3:
						if (!did[i]){
							did[i]++;
							printf("Are you right?\n");
							printf("1.I am right.\n");
							printf("2.I am wrong.\n");
							while (1){
								input_ok_right = 1;
								scanf("%s", buf);
								is_right = buf[0] - '0';
								switch (is_right){
									case 1:
										rights_and_wrongs[i] = 1;
										break;
									case 2:
										rights_and_wrongs[i] = 0;
										break;
									default:
										printf("Your input is ineffective, please input again!\n");
										input_ok_right = 0;
										break;
								}
								if (input_ok_right){
									break;
								}						
							}
						}
						if (i < tested_num - 1){
							i++;
						}
						break;
					case 4:
						for (int j = 0; j < dict_capa; j++){
							if (!strcmp(dict_freq->word[index], dict_abc->word[j])){
								loc = j;
								break;
							}
						}
						if ((fp_star = fopen("star.txt", "a+")) != NULL){
							fseek(fp_star, 0, SEEK_END);
							fprintf(fp_star, "%d,%d\n", 0, loc);
							fprintf(fp_star, "%d,%d\n", 1, index);
							fclose(fp_star);
							fp_star = NULL;
						}
						dict_abc->star[loc] = 1;
						dict_freq->star[index] = 1;
						break;
					case 5:
						return show_test_main_interf();
					case 6:
						return 0;
					default:
						printf("Your input is ineffective, please input again!\n");
						input_ok = 0;
						break;
				}	
				if (input_ok){
					break;
				}
			}
		}
		did_num = 0;
		for (int j = 0; j < tested_num; j++){
			did_num += did[j];
		}
		if (did_num >= tested_num ){
			break;	
		}
	}
	int sum = 0;
	for (int j = 0; j < tested_num; j++){
		sum += rights_and_wrongs[j];
	}	
	float f = 100 * (float) sum / tested_num;
	system("cls");
	printf("Test is over, your grade is below.\n\n");
	printf("There are %d word(s) in this test, you remember %d of them, your correct percentage is %.2f%%.\n", tested_num, sum, f);
	printf("Your tested words are shown below.\n");
	for (int j = 0; j < tested_num; j++){
		index = index_list[j];
		if (rights_and_wrongs[j]){
			if (dict_freq->star[index]){
				printf("\033[36m%s *: \t%s\033[0m\n", dict_freq->word[index], dict_freq->meaning[index]);
			} else{
				printf("\033[36m%s: \t%s\033[0m\n", dict_freq->word[index], dict_freq->meaning[index]);
			}
		} else{
			if (dict_freq->star[index]){
				printf("\033[31m%s *: \t%s\033[0m\n", dict_freq->word[index], dict_freq->meaning[index]);
			} else{
				printf("\033[31m%s: \t%s\033[0m\n", dict_freq->word[index], dict_freq->meaning[index]);
			}
		}
	}
	printf("Input a number to continue: ");
	printf("1.Back.");
	printf("2.Exit.");
	while (1){
		input_ok = 1;
		scanf("%s", key);
		num = key[0] - '0';
		switch (num){
			case 1:
				return show_test_main_interf();
			case 2:
				return 0;
			default :
				printf("Your input is ineffective, please input again!\n");
				input_ok = 0;
				break;
		}
		if (input_ok){
			break;
		}
	}
	return 0;
}

int view_dict(Dict* dict_freq, Dict* dict_abc, int mode){
	char buf[100];
	switch (mode){
		case view_dict_freq_interf:
			for (int i = 0; i < dict_capa; i++){
				if (dict_freq->star[i]){
					printf("\033[36m%s *: \t %s\033[0m\n", dict_freq->word[i], dict_freq->meaning[i]);
				} else{
					printf("%s : \t %s\n", dict_freq->word[i], dict_freq->meaning[i]);
				}
			}
			printf("Input any number to continue.\n");
			scanf("%s", buf);
			return show_dict_main_interf();
		case view_dict_abc_interf:
			for (int i = 0; i < dict_capa; i++){
				if (dict_abc->star[i]){
					printf("\033[36m%s *: \t %s\033[0m\n", dict_abc->word[i], dict_abc->meaning[i]);
				} else{
					printf("%s : \t %s\n", dict_abc->word[i], dict_abc->meaning[i]);
				}
			}
			printf("Input any number to continue.\n");
			scanf("%s", buf);
			return show_dict_main_interf();
		case view_dict_star_interf:
			for (int i = 0; i < dict_capa; i++){
				if (dict_abc->star[i]){
					printf("\033[36m%s *: \t %s\033[0m\n", dict_abc->word[i], dict_abc->meaning[i]);
				}
			}
			printf("Input any number to continue.\n");
			scanf("%s", buf);
			return show_dict_main_interf();
		default:
			return 0;
	}
}

int plot_heart(){
	system("cls");
	double x,y,a;
    for(y=1.5;y>-1.5;y-=0.1214)  //调好的参数，爱心形状，可以自行调参数，改变爱心的形状
    {
        for(x=-1.5;x<1.5;x+=0.05)
        {
            a=x*x+y*y-1;
            if(a*a*a-x*x*y*y*y<=0)    //爱心方程
               {
                printf("\033[31m*\033[0m");
               }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Input any number to return main interface.\n");
    char buf[10];
    scanf("%s", buf);
    return back_2_main_interf();
}

int delete_all_star(Dict* dict1, Dict* dict2){
	system("cls");
	printf("Are you sure you want to Delete all your stars(*)?\n");
	printf("1.Sure.\n");
	printf("2.Cancel.\n");
	char key[100];
	int num;
	while (1){
		scanf("%s", key);
		num = key[0] - '0';
		switch (num){
			case 1:
				FILE* fp;
				if ((fp = fopen("star.txt", "w")) != NULL){
					fclose(fp);
					fp = NULL;
					for (int i = 0; i < dict_capa; i++){
						dict1->star[i] = 0;
						dict2->star[i] = 0;
					}
					printf("Delete stars completely!\n");
    				printf("Input any number to return main interface.\n");
					scanf("%s");
					return back_2_main_interf();
				}
				return 0;
			case 2:
				return back_2_main_interf();
			default:
				printf("Your input is ineffective, please input again!\n");
				break;
		}
	}
}

int show(int interf, Dict* dict_freq, Dict* dict_abc){
	switch (interf){
		case 1:
			return show_alpha_order_interf();
			case 11:
				return learn(dict_abc, dict_freq, 1);
			case 12:
				return learn(dict_abc, dict_freq, 0);
			case 13:
				return back_2_main_interf();
			case 14:
				return 0;
		case 2:
			return show_freq_order_interf();
			case 21:
				return learn(dict_freq, dict_abc, 1);
			case 22:
				return learn(dict_freq, dict_abc, 0);
			case 23:
				return back_2_main_interf();
			case 24:
			return 0;
		case 3:
			return rand_learn(dict_abc, dict_freq);
		case 4:
			return show_test_main_interf();
			case 41:
				return test(dict_freq, dict_abc, dict_capa / 4);
			case 42:
				return test(dict_freq, dict_abc, dict_capa / 2);	
			case 43:
				return test(dict_freq, dict_abc, dict_capa - 2);	
			case 44:
				return back_2_main_interf();
			case 45:
				return 0;
		case 5:
			return show_dict_main_interf();
			case 51:
				return view_dict(dict_freq, dict_abc, view_dict_freq_interf);
			case 52:
				return view_dict(dict_freq, dict_abc, view_dict_abc_interf);
			case 53:
				return view_dict(dict_freq, dict_abc, view_dict_star_interf);
			case 54:
				return back_2_main_interf();
			case 55: 
				return 0; 
		case 6:
			return plot_heart();
		case 7:
			return delete_all_star(dict_abc, dict_freq);
		case 8:
			return 0;
		default:
			return back_2_main_interf();
	}
	return 1;
}

Dict init(Dict* dict, char* path) {
	srand((unsigned)time(NULL));
	int is_freq;
    FILE* fp = NULL;
    char buffer[1024];
    if ((fp = fopen(path, "r")) != NULL) {
        fseek(fp, 0, SEEK_SET);
        char* line, *token;
        char delims[] = ",";
        int i = 0;
        while ((line = fgets(buffer, sizeof(buffer), fp)) != NULL) {
            token = strtok(line, delims);
            if (token != NULL) {
                strcpy(dict->word[i], token);
                if ((token = strtok(NULL, delims)) != NULL) {
                    if (token[strlen(token) - 1] == '\n'){
                    	token[strlen(token) - 1] = '\0';
					}
                    strcpy(dict->meaning[i], token);
                    dict->star[i] = 0;
                }
            }
            i++;
            if (i >= dict_capa) {
                break;
            }
        }
        fclose(fp);
        fp = NULL;
    }
    is_freq = dict->word[0][0] != 'a';
    int loc;
    if ((fp = fopen("star.txt", "r")) != NULL){
    	fseek(fp, 0, SEEK_SET);
    	char* line, *token;
        char delims[] = ",";
        while ((line = fgets(buffer, sizeof(buffer), fp)) != NULL) {
            if ((token = strtok(line, delims)) != NULL) {
                if ((token[0] - '0') != is_freq){
                	continue;
				}	
				if ((token = strtok(NULL, delims)) != NULL){
					loc = 0;
					for (int i = 0; i < strlen(token); i++){
						if ('0' <= token[i] && token[i] <= '9'){
							loc = loc * 10 + (token[i] - '0');
						}
					}
					dict->star[loc] = 1;
				}
            }
        }
        fclose(fp);
        fp = NULL;
	}
    return *dict;
}

int main() {
	char path_freq[] = "Dict.csv";
	char path_abc[] = "Dict_ABC.csv";
	Dict dict_freq;
	Dict dict_abc;
    dict_freq = init(&dict_freq, path_freq);
    dict_abc = init(&dict_abc, path_abc);
    while (1) {
    	if (!show(now_interf, &dict_freq, &dict_abc)){
    		printf("Goodbay, expect your next learning and good luck to you!\n");
    		break;
		}
    	char key[100]; 
    	while (1){
    		printf("Your input: ");
    		scanf("%s", key);
			if (in_appr_interf(now_interf * 10 + key[0] - '0')){
				now_interf = now_interf * 10 + key[0] - '0';
				break;
			}	
			printf("Your input is ineffective, please input again!\n");
		}
	}
    getchar();
    return 0;
}

