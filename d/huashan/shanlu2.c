
inherit ROOM;
void night_event();
void sunrise_event();
string tree();
string stream();
void create()
{
        set("short", "山路");
        set("long", @LONG
沿山路再向西行即莲花峰，小路从枫树林中穿过，风从树林中穿过，树叶在你
的头上哗哗做响，枫叶呈五角形，每到秋深霜浓时节，满山红叶如炽，别是一番景
色。一条小溪从山上流下，穿过枫林山下流去。
LONG
        );
    set("exits", ([ 
        "southeast" : __DIR__"shanlu1",
        "westup" : __DIR__"lianhua",
	]));

	set("item_desc", ([
		"maple tree" : (: tree :),
		"枫树" : (: tree :),
//		"stream" : (: stream :),
//		"小溪" : (: stream :),
	]));
	
	set("objects", ([
		__DIR__"obj/nest" : 1,
	]));
    set("outdoors", "huashan");

	set("coor/x",-65);
	set("coor/y",-55);
	set("coor/z",36);
	setup();
	NATURE_D->add_day_event(19, 0, this_object(), (: night_event :)); 
}

string tree(){
	object me;
	int i;
	i = NATURE_D->get_season();
	me = this_player();
	if(i == 3){
		tell_object(me, "满树的枫叶红的似火。\n");
		call_out("leaf_fall", random(40));
	} else if(i == 4) {
		tell_object(me, "光秃秃的树干上可以看到几个小小的鸟窝。\n");
	} else {
		tell_object(me, "树叶随风动，发出哗啦啦的声响。\n"); 
	}
	return "";
}

void leaf_fall(){
	object leaf;
	if(!leaf = present("maple leaf", this_object())) {
		leaf = new(__DIR__"obj/mapleleaf");
		leaf->move(this_object());
		message("vision", "一片枫叶随风飘下。\n", this_object());
	}
}

void night_event() {
	object qing;
	object room = this_object();
	if(!random(2)){
		qing = new(__DIR__"npc/qing");
		qing->move(room);
		message_vision("忽然有一阵风吹过来，风中仿佛有个影子。一条淡淡的影子，带着种淡淡的香气。\n", qing);
		NATURE_D->add_day_event(6, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(19, 0, this_object(), (: night_event :));
	}
}

void sunrise_event() {
    object *ob_list;
    int i;
    
    ob_list = children("/d/huashan/npc/qing");
    for(i=0; i<sizeof(ob_list); i++) {
        if(environment(ob_list[i])) {
        	message_vision("一阵香气拂过，$N已失去了踪影，只留下淡淡的香气。\n",ob_list[i]);
        }
        destruct(ob_list[i]);
    }
    NATURE_D->add_day_event(19, 0, this_object(), (: night_event :));
}
