// Room: darklane1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "暗巷");

	set("long", @LONG
小巷又窄又暗，一阵阵又湿又冷的风似鬼魂般时有时无，你不禁打了个寒战。
血腥之气弥漫在空气之中，一种莫名的恐怖，强烈的恐怖，梦魇般压住了你的心
头。血，遍地的血；尸骸，残缺的尸骸……
LONG);

	set("type","street");
	set("exits",([
		"south":__DIR__"stoneroad2",
		"north":__DIR__"darklane2",
	]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);


	setup();
}

void init()
{
        add_action("do_look","look");

}

int do_look(string arg)
{
    	object corpse;
    
    	if (!arg) return "cmds/std/look"->main(this_player(),"");
    	else 
    		if (arg != "尸骸"&&arg!="corpses") return 0;
    	
    	write("你发现地上躺着几具尸体，好象死了还不到一个时辰。\n");
    	corpse=present("bloody corpse",this_object());
     	
     	if( !objectp(corpse)) 
     	{
    		corpse = new(__DIR__"obj/corpse");
    		corpse->set("no_get",1);
    		corpse->move(this_object());
    		corpse = new(__DIR__"obj/corpse");
    		corpse->set("no_get",1);
    		corpse->move(this_object());
    		corpse = new(__DIR__"obj/corpse");
    		corpse->set("no_get",1);
    		corpse->move(this_object());
    	}
    	if(!this_player()->query_temp("libie/离别钩_发现尸体"))
    	this_player()->set_temp("libie/离别钩_发现尸体",1);
    	return 1;
}
