// save.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

int save() {
	string file;
	
	if(stringp(file = this_object()->query_save_file())) {
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int restore() {
	string file;
	
	if(stringp(file = this_object()->query_save_file())) {
		return restore_object(file);
	}
	return 0;
}
