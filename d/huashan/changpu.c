
inherit ROOM;
string plant();
void create()
{
        set("short", "菖蒲池");
        set("long", @LONG
山半腰有个小池塘，水色明亮如镜而且终年不干，一路走来却也不见有溪流
注入其中。池畔生长着一些碧绿的植物，微微山风吹来，狭长的叶子随风摆动，
空气中似乎漂浮着一种淡淡的香气。
LONG
        );
    set("exits", ([ 
  		"westup" : __DIR__"yuquan",
  		"eastdown" : __DIR__"zhuyu",
		"north" : __DIR__"zhandao",
	]));
   
   	set("item_desc", ([
   		"植物" : (: plant :),
   		"plant" : (: plant :),
   	]) );
    set("cpleaf_amount", 3);
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-20);
	setup();
}

string plant(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if (i == 4) {
		tell_object(me, "小水塘上浮着一层薄冰，水边的植物都已枯黄。\n");		
	} else {
		tell_object(me, "浅水中生有一丛丛的绿色植物，狭长的叶子带有微微的香气。\n");
		add_action("do_pick", "pick");
	}
	return "";
}
int do_pick(string arg){
	object obj, me;
	int i;
	me = this_player();
	if(!arg || (arg != "leaf" && arg != "菖蒲" && arg != "plant" )) {
		return 0;
	}
	if(query("cpleaf_amount") > 0) {
		obj = new(__DIR__"obj/cpleaf");
		if(objectp(obj)){
			obj->move(me);
			message_vision("$N摘了几片叶子放入怀中。\n", me);
			add("cpleaf_amount", -1);
		}
	} else {
		tell_object(me, "没有了。\n");
	}
	return 1;
}
void reset(){
	::reset();
	set("cpleaf_amount", 3);
}
