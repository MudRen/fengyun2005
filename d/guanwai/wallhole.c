inherit ROOM;

void create()
{
        set("short", "穹形石窟");
        set("long", @LONG
这是在大昭寺右壁上的石窟。窟里有一幅色彩鲜艳但却恐怖之极的壁画。画上
是一个狰狞娇异的罗刹鬼女，正在吮吸一个凡人的脑髓。精密细致的画面看来栩栩
如生。
LONG
        );
        
        set("exits", ([ 
		"east" : __DIR__"woodhouse",
		"south" : __DIR__"templeyard",
	]));
	set("objects", ([
                __DIR__"npc/qi" : 1,
        ]) );       

	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_sware", "swear");
}

int do_sware()
{
        object me,obj;
        me = this_player();
        obj = present("qi xiaoyan", this_object());
        
        message_vision("$N郑重地对着墙上的罗刹立下毒誓：若我泄密，就如同墙上这男子一样\n被罗刹鬼女吸干脑髓．．．\n", me);
        if( me->query_temp("marks/guanwai_knowsecret") )
        	call_out("open_path",2,me,obj);
        return 1;

}

void open_path(object me, object obj)
{
    if (!obj || !me || environment(obj)!= environment(me))	return;
    	
    message_vision("$N满意地点了点头，伸手往墙上一块石砖上一摸一揿。石壁缓缓\n移开，露出了间密窟。\n", obj);
 	if( !query("exits/west") ) 
 	{
		set("exits/west", __DIR__"secretroom");
		call_out("close_path", 5);
	}
}

void close_path()
{
        if( !query("exits/west") ) 
        	return;
        message("vision","石壁轧轧做响，又挡住了去路。\n",this_object() );
	delete("exits/west");
}