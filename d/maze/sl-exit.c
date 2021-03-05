// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "帝释天殿前");
	set("long", @LONG
帝释天乃众神首领，但佛经中言：一切皆无常。帝释天也会寿尽而亡，所谓天 
人五衰即为：衣裳垢腻、头上花萎、身体臭秽、腋下汗出、不乐本座。帝释天殿乃 
少林一百零八堂的主殿，只有佛法高深的少林弟子方有机会至此求道宣法。还未入
殿，但闻殿中佛号声声，震人心寰。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"sl-maze/exit",
		"east" : __DIR__"sl-end",
	]));
        set("objects", ([
                             
        ]) );
        
        set("item_desc", ([
		"east": "一个硕大的铁笼放在正中，两个年愈百岁的老僧盘膝两旁。。\n",
	]) );
	setup();
	
}

int	valid_leave(object who , string dir) {
	object room, guo;
	
	if (dir == "east") 
	{
		room = find_object(__DIR__"sl-end");
                if (room && room->usr_in())
			return notify_fail("殿中似乎有人正在争斗，且静观其变。\n");
		if (REWARD_D->riddle_check(who,"勇入少林")<2
				&& !REWARD_D->check_m_success(who,"勇入少林"))
			return notify_fail("你为殿中佛号所震，竟然迈不开脚步。\n");
		if (room) {
			if (guo = present("afei",room))
				destruct(guo);
			room->reset();
		}
	}
	return ::valid_leave(who,dir);
}