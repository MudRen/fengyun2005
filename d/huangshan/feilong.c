// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "飞龙峰");
    set("long", @LONG
这里很少有游人前来，因此山势险恶，且无什么绝妙的景色，但是武林人士倒
喜欢来此探幽，更曾有高人隐居于此，所以后来者更是络绎不绝，期待能够得到那
传说中的秘宝。可是山顶怪石林立，杂草丛生，丝毫不见有人的迹象，但是谁也不
肯放弃希望，都要搜一搜。
LONG
        );
    set("exits", ([ 
  		"southeast" : __DIR__"qingliang",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",30);
	setup();
}
void init()
{
	add_action("do_search","搜");
	add_action("do_search","search");
	add_action("do_search","sou");
}
int do_search()
{
	string *names = ({"脏脏的","划破的","撕成条的","沾满污泥的"});
	object clo,me;
	me = this_player();
	clo = new("/obj/armor/cloth");
	clo->set("name",names[random(sizeof(names))]+"布衣");
	message_vision("$N在这怪石林立，杂草丛生的山顶不停地搜寻着．．\n",me);
	if(!me->is_busy())
	{
		tell_object(me,"你发现了一件"+clo->name()+"。\n");
		clo->move(me);
	}
	me->start_busy(4);
	return 1;
}
