//By Clone
//2001
#include <ansi.h>

inherit ITEM;

void create(){
	set_name("小马求援信",({"xiaoma note"}) );
	set("unit","封");
	set("long","\n一块从衣襟上扯下来的破布，上面用血潦草地写着几个字："+
			
		"被困狼山，快来救命！！！

					小马\n");
	set_weight(1);
	::init_item();
}
