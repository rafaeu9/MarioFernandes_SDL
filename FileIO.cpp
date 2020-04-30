#include "FileIO.h"



void FileIO::ReadLevel()
{
	
	FILE* fp = fopen("data/Level1.txt", "r");

	

		if (!fp) {
			std::perror("data/Level1.txt failed to open\n");
		}
		else {
			printf("data/Level1.txt successfully open\n");
		}		


	while (true) {

		char type[256];

		if (fp)
		int val = fscanf(fp, "%s", &type);
		else
			printf("data/Level1.txt problem\n");

		//if(val<=0)
		//{
		//	fclose(fp);
		//	break;
		//}

		if (strstr("Level2", type) != 0)
		{
			/*int a, b, c;
			val = fscanf_s(fp, "%d %d %d",
								&a, &b, &c);*/

			printf("Level 2\n");
			fclose(fp);
			/*getchar();*/
			break;
		}
		else {
			
		}


		//else
		//	if (strstr("player", type) != 0)
		//	{
		//		int a, b;
		//		val = fscanf_s(fp, "%d %d",
		//							&a, &b);
		//		printf("Player script valudes: %d %d\n", a, b);
		//		getchar();
		//		
		//	}
		//	else
		//	{
		//		printf("Unknown command/value in script\n");
		//		
		//	}
	}
}
