#include <stdio.h>
#include <string.h>


void quaility_hander (char *h_device, char *w_device, char *qualities_mpd){


	char buf[100]="";
	int i = 0;
	char *qualities[10];
	char *resolution_to_check[2];
	char *bitrate_to_check[0];
	char *token_w,*token_h;
	int  with,height;
	//Loop variables
	int number_qualities = 0;
	int index_to_check = 0;
	//Print inputs
	printf("-----\n");
	printf( "%s\n", h_device );
	printf( "%s\n", w_device );
	printf( "%s\n", qualities_mpd );

	//Copy quality to temp char
	memset(buf, '\0', sizeof(buf));
	strcpy(buf, qualities_mpd);
	char *p = strtok (buf, ",");
	printf( "%s\n", p );

	//Parse qualities and obtain number of this
	while (p != NULL)
	{
		printf( "%s\n", p );

		qualities[i++] = p;
		p = strtok (NULL, ",");
		number_qualities++ ;

	}
	printf ("Number of qualities %d\n ", number_qualities);

	//For debug
	printf("Print all qualities:\n");
	printf("-----\n");
	for (i = 0; i < number_qualities; ++i)
		printf("%s\n", qualities[i]);
	printf("-----\n");


	for (i = 0; i < number_qualities; ++i){
		resolution_to_check[i] = strtok (qualities[i], "_");
		token_w = strtok(resolution_to_check[i], "x");
		token_h = strtok(NULL, "x");
		with = atoi(token_w);
		height =atoi(token_h);

		printf("--Int--\n");
		printf( "%d\n", with );
		printf( "%d\n", height );
	}

}

int main ()
{

	char *h_device = "800";
	char *w_device = "600";
	char *qualities_mpd = "480x240_3.23,600x300_5.22,1920x1080_5.22,2048x1024_5.22,200x200_1.3";
	quaility_hander ( h_device,  w_device,  qualities_mpd);

    return 0;
}
