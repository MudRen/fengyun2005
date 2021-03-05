// autoload.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/14/2001 by Daniel Q. Yu.
//

string *autoload;

void clean_up_autoload() { 
	autoload = 0; 
}

void save_autoload() {
	object *inv;
	int i, j;
	mixed param;

	inv = all_inventory();
	autoload = allocate(sizeof(inv));
	for(i=0, j=0; i<sizeof(inv); i++) {
		if(!(param = inv[i]->query_autoload())) {
			continue;
		}
		autoload[j] = base_name(inv[i]);
		if(stringp(param)) {
			autoload[j] += ":" + param;
		}
		j++;
	}
	autoload = autoload[0..j-1];
}

void restore_autoload() {
	int i;
	object ob;
	string file, param, err;

	if(!pointerp(autoload)) {
		return;
	}
	for(i=0; i<sizeof(autoload); i++) {
		if( sscanf(autoload[i], "%s:%s", file, param)!=2 ) {
			file = autoload[i];
			param = 0;
		}
		err = catch(ob = new(file));
		if( err || !objectp(ob) ) {
			write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
			log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
				file, this_object()->query("name"), err));
			continue;
		}
		export_uid(ob);
		ob->move(this_object());
		ob->autoload(param);
	}
	clean_up_autoload();		// To save memory.
}
