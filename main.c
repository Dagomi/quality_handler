#include <stdio.h>
#include <string.h>


char *quaility_handler (char *h_device, char *w_device, char *qualities_mpd){


	char buf[100]="";
	int i = 0;
	char *qualities[10];
	char *resolution_to_check[2];

	char *token_w,*token_h,*bw;
	int  with,height;
	int  with_device,device_height;
	int max_bw;
	//Loop variables
	int number_qualities = 0;
	int index_to_check = 0;

    char *string = malloc(5);

	//Print inputs
	with_device = atoi(w_device);
	device_height = atoi(h_device);
	printf("------\n");
	printf( "%d\n", device_height );
	printf( "%d\n", with_device );
	printf( "%s\n", qualities_mpd );
	printf("------\n");

	//Copy quality to temp char
	memset(buf, '\0', sizeof(buf));
	strcpy(buf, qualities_mpd);
	char *p = strtok (buf, ",");

	//Parse qualities and obtain number of this
	while (p != NULL)
	{
		qualities[i++] = p;
		p = strtok (NULL, ",");
		number_qualities++ ;

	}
	printf ("Number of qualities %d\n", number_qualities);
	char *bitrate_to_check[number_qualities];
	for (i = 0; i <= number_qualities - 1; ++i){

		token_w = strtok (qualities[i], "x");
		token_h = strtok(NULL, "_");
		bitrate_to_check[i] = strtok (NULL, "_");
		printf("bitrate_to_check to: %s\n", bitrate_to_check[i]);

		with = atoi(token_w);
		height =atoi(token_h);

		//Set minimum quality supported
		if (with > 100){
			if ( with < with_device){
				printf("MPD Quality  %d less than %d\n",with, with_device);
				printf("Bitrate to: %s\n", bitrate_to_check[i]);
				printf("The quality IS supported.\n");
			    strcpy(string, bitrate_to_check[i]);
			    return string;
			}else{
				printf("MPD Quality %d highest than %d\n",with, with_device);
				printf("The quality is NOT supported.\n");
			}
		}

	}
	printf("Return %s \n", bitrate_to_check[number_qualities - 1]);
    strcpy(string, bitrate_to_check[number_qualities - 1]);
    return string;

}

int main ()
{
	char *w_device = "2561";
	char *h_device = "300";
	char *qualities_mpd = "3840x2160_7.0,2560x1440_6.0,1920x1080_5.0,1280x720_4.0,854x480_3.0,640x360_2.0,426x240_1.0";
//	char *qualities_selected;
	char *qualities_selected = quaility_handler ( h_device,  w_device,  qualities_mpd);
	printf("Return %s \n", qualities_selected);
	free(qualities_selected);

    return 0;
}
