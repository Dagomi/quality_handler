#include <stdio.h>
#include <string.h>


void quaility_hander (char *h_device, char *w_device, char *qualities_mpd){

//	char h_device = "800";
//	char w_device = "600";
//	char qualities_mpd = "480x240_3.23,600x300_5.22,1920x1080_5.22,2048x1024_5.22";
	printf("-----\n");
	printf( "%s\n", h_device );
	printf( "%s\n", w_device );
	printf( "%s\n", qualities_mpd );
//
	char buf[100]="";
//	char temp[100]="";
	int i = 0;
	char *qualities[10];
//	char *resolution_to_check[2];
//	char *bitrate_to_check[0];
	int number_qualities = 0;
//	char *token_w,*token_h;
//	int  with,height;
//
//	printf("--asi---\n");
//
//	qualities = qualities_mpd;
//	printf( "%s\n", qualities );
//
	memset(buf, '\0', sizeof(buf));
//	strcpy(temp, qualities);
	strcpy(buf, qualities_mpd);
//
	char *p = strtok (buf, ",");
	printf( "%s\n", p );

//

	while (p != NULL)
	{
		printf( "%s\n", p );

		qualities[i++] = p;
		p = strtok (NULL, ",");
		number_qualities++ ;

	}
	printf ("Number of qualities %d\n ", number_qualities);
//	printf("Print all qualities:\n");
	printf("-----\n");
	for (i = 0; i < number_qualities; ++i)
		printf("%s\n", qualities[i]);
	printf("-----\n");
//
//	resolution_to_check[0] = strtok (qualities[0], "_");
//
//	printf("%s\n", resolution_to_check[0]);
//
//	/* get the first token */
//	token_w = strtok(resolution_to_check[0], "x");
//	token_h = strtok(NULL, "x");
//
//	printf("--Char--\n");
//	printf( "%s\n", token_w );
//	printf( "%s\n", token_h );
//
//	with = atoi(token_w);
//	height =atoi(token_h);
//
//	printf("--Int--\n");
//	printf( "%d\n", with );
//	printf( "%d\n", height );

}

int main ()
{

	char *h_device = "800";
	char *w_device = "600";
	char *qualities_mpd = "480x240_3.23,600x300_5.22,1920x1080_5.22,2048x1024_5.22";
	quaility_hander ( h_device,  w_device,  qualities_mpd);

    return 0;
}
