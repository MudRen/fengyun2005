inherit ROOM;
void create()
{
        set("short", "地下石室");
        set("long", @LONG
这里是一间鸽笼大小的石室，厚重的青石墙散着浅浅的潮气，石室一角的木床
上血痕斑斑。潮气、汗臭、腥气，还有一些奇异的甜香，混成熏人欲呕的异味，让
你迫切的想要离开这里。
LONG
        );
        set("exits", ([ 
  	"up" : __DIR__"huangyuan",
]));

	set("indoors","qianjin");
	set("no_fly",1);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",-20);
	
	set("objects", ([
		__DIR__"npc/meihuadao" : 1,
	]));   	
//	set("valid_startroom", 1);
	setup();

}

void init()
{
//        if(!wizardp(this_player()))
	{
//	"/cmds/std/look"->look_room(this_player(),this_object());
        	add_action("do_nothing", "");
        	add_action("do_look","look");
        	add_action("do_chat","chat");        
        	add_action("do_emote","chat*");                
		add_action("do_quit","quit");
	}
}	

int do_nothing(string arg)
{
	if (this_player()->query_temp("marks/meihuadao"))
	{
		write("你心下大急，百般挣扎，无奈穴道被点，一动也不能动．．．．！\n");
		return 1;
	}
	else return 0;
}

int do_chat(string arg)
{
	CHANNEL_D->do_channel(this_player(), "chat", arg);
	return 1;
}

int do_emote(string arg)
{
	CHANNEL_D->do_channel(this_player(), "chat*", arg);
	return 1;
}

int do_look(string arg)
{
    	"/cmds/std/look"->main(this_player(),arg);
    	return 1;
}

int do_quit()
{
	"/cmds/usr/quit"->main(this_player(),"");
	return 1;
}

