inherit ROOM;

void create()
{
	set("short", "白云深处");

	set("long", @LONG
		“远上寒山石径斜，白云深处有人家。”
一切如在诗画之中，红红绿绿的烂漫山花之间，掩映着一道竹篱，篱后三三两两错
落着几间简陋的草堂。斜斜的石径上落英缤纷，一个白发苍苍的跛足老人，正弯著
腰，在慢慢的扫著石径上的落花。(过跛足老人需交３两黄金) 
LONG);

	set("type","road");
	set("exits",([
		"southup":__DIR__"flowers",
		"northwest":__DIR__"fogpath",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/oldman":1,
    	]) ); 
	set("coor/x",40);
	set("coor/y",-70);
	set("coor/z",30);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southup" && ob=present("lame oldman", this_object()) ) 
        {
		if ( !me->query("marks/wolf_pass_oldman"))
		{
            return notify_fail(ob->name()+"还在扫花，扫着那些永远扫不尽的落花，有意无意中挡住你的去路．\n");
		}
	}
	return 1;
}
