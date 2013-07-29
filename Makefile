###############################################################################
# 	Makefile
#
# A library of parsers for various file types
# 
# AUTHOR : Jennifer Winer
#
# CREATED : July 10, 2013
# LAST MODIFIED : July 10, 2013
###############################################################################

#compiler options
CC		= gcc
C_FLAGS 	= -fPIC -O3 -MMD -MP 
C_INCLUDES   	= =I. -I../../include

L_FLAGS		= -shared 
L_INCLUDES	= -L../../lib -lconfuse


#directory names
OBJ_DIR		= obj

OBJS		= $(addprefix $(OBJ_DIR)/, \
			architecture_library.o \
			dfg_library.o \
			hardware_library.o)

PROG_NAME	= libcommonInterfaces.so

###############################################################################
#      compilation, linking and debugging targets
###############################################################################


all : $(PROG_NAME)
	@ echo "Build updated"
	
clean : 
	rm -f $(PROG_NAME)
	rm -f $(OBJ_DIR)/*

.PHONY : $(PROG_NAME) 


$(PROG_NAME) : $(OBJS)
	$(CC) $(L_FLAGS) $(OBJS) -o $(PROG_NAME) $(L_INCLUDES) 
	cp common_interfaces.h  ../../include/
	cp $(PROG_NAME) ../../lib/
	
$(OBJ_DIR)/%.o: %.c $(OBJ_DIR) 
	$(CC) $(C_INCLUDES) $(C_FLAGS) -c $< -o $@
    
$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)
