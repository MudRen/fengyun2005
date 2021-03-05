
inherit ROOM;
string flower();
void create()
{
        set("short", "荒凉小径");
        set("long", @LONG
小路渐渐深入树林，树冠遮蔽了天日，即使在白天这里也显得十分阴暗，茂密
的杂草几乎覆盖了整个路面，有些地方小路几不可辨。不远处一段断墙横在路旁，
断墙旁长满了一丛丛的野菊。
LONG
        );
    set("exits", ([ 
		"west" : __DIR__"hpath1",
		"east" : __DIR__"citang1",
	]));
 	set("objects", ([
 		__DIR__"obj/duanqiang" : 1,
 	]) );  
 	set("item_desc", ([
 		"flower" : (: flower :),
 		"野菊" : (: flower :),
 	]) );
 	set("flower_amount", 5);
    set("outdoors", "huashan");
	set("coor/x",-8);
	set("coor/y",15);
	set("coor/z",-10);

	setup();
}

string flower(){
	int i;
	i = NATURE_D->get_season();
	if(i == 3) {
		tell_object(this_player(), "断墙边的野菊花开得正红火。你可以摘几朵（ｐｉｃｋ　ｆｌｏｗｅｒ）。\n");
		add_action("do_pick", "pick");
	} else if(i == 4) {
		tell_object(this_player(), "断墙下积满了残雪，几根焦黄的茅草在寒风中瑟缩着。\n");
	} else {
		tell_object(this_player(), "断墙下长满了茂密的野草还有野菊花。\n");
	}
	return "";
}

int do_pick(string arg){
	object me, obj;
	
	if(!arg || arg != "flower"){
		return 0;
	}
	me = this_player();
	if(query("flower_amount") >= 0) {
		message_vision("$N弯腰在断墙边摘了一朵野菊花。\n", me);
		obj = new(__DIR__"obj/flower");
		if(objectp(obj)){
			obj->move(me);
		}
		add("flower_amount", -1);
		return 1;
	}
	tell_object(me,"野菊花已经被摘完了。\n");
	return 1;
}

void reset(){
	::reset();
	set("flower_amount", 5);
}
