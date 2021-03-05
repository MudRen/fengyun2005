inherit ROOM;

void create()
{
	set("short", "鹰愁涧");

	set("long", @LONG
山路崎岖难行，四面悬崖峭壁如犬牙交错，远远望去叠岭层峦连绵不断。水声
震耳欲聋，只见山峰间一条白龙似的瀑布奔泻而下，冲入一条溪流，奔胜雷鸣，湍
急异常，水中挟著树枝石块，转眼便流得不知去向，这里便是狼山上又一处自然天
险“鹰愁涧”。山涧不远处竟似乎有间茅草屋依山而建。
LONG);

	set("type","mountain");
	set("exits",([
		"northdown":__DIR__"wolfslope",
		"southeast":__DIR__"safepub",
	]) );
       set("outdoors", "wolfmount");
        set("item_desc", ([
                "山涧": "山涧奔流不息，水流湍急，但却十分清澈。\n",
                "fountain": "山涧奔流不息，水流湍急，但却十分清澈。\n",
        ]) );
    set("resource/water",1);
	set("liquid/name","鹰愁涧水");
	set("liquid/type", "water");
	set("objects",([
     		__DIR__"npc/tiezhan":1,
    	]) );
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
