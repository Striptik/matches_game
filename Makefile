all:
	@echo -e "\n\n\t\t\t\tLIBRARY COMPILATION\n"
	cd my/; make
	@echo -e "\n\n\t\t\t\tSOURCES COMPILATION\n"
	cd src/; make

clean:
	@echo -e "\n\n\t\t\t\tDELETE OBJECTS FILES\n"
	cd my/; make clean
	cd src/; make clean

fclean:
	@echo -e "\n\n\t\t\t\tDELETE BINS LIBRARY AND OBJECTS FILES\n"
	cd my/; make fclean
	cd src/; make fclean

re: fclean all

.PHONY: all clean fclean re
