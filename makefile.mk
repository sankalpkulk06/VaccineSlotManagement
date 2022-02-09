integrated_ver_4.exe : slot_booking.o login_signup_functions.o view_details.o client.o
	gcc slot_booking.o login_signup_functions.o view_details.o client.o -o integrated_ver_4
client.o : client.c header.h
	gcc -c client.c
login_signup_fns.o : login_signup_functions.c header.h
	gcc -c login_signup_functions.c
slot_booking.o : slot_booking.c header.h
	gcc -c slot_booking.c
view_details.o : view_details.c header.h
	gcc -c view_details.c