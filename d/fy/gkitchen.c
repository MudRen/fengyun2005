inherit ROOM;

void create()
{
    set("short", "镖局厨房");
    set("long", @LONG
金狮镖局对伙计们十分款待，不但每月有薪金，而且还包吃住。这里就是伙计
们一日三餐的地方。厨房的墙上挂满了锅碗瓢盆，还有一些风干的卤味儿。房中放
着一张[33m长台[32m，长台的周围摆着几条[33m长凳[32m。油烟弥漫中，几个厨子忙得不可开交。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/goldcook" : 1,
	__DIR__"obj/wall": 1,

      ]) );

    set("coor/x",140);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}

void init(){
    add_action("do_look","look");
}


int do_look(string arg){

    if (arg == "table")	arg = "长台";
    if (arg == "stool")	arg = "长凳";

    if (arg == "长台" || arg == "长凳") {
	if (!this_player()->query_temp("marks/js_cook_mice")) {
	    tell_object(this_player(),"这是一张很普通的"+ arg + "，上面沾满了油烟。\n");
	    return 1;
	}
	tell_object(this_player(),"大厨一提醒你才发现，这桌上椅上都有老鼠跑过的痕迹，一直延伸到院子里。\n");
	this_player()->set_temp("marks/js_cook_mice",2);
	return 1;
    }
    return 0;
}

void reset()
{
    object          *inv;
    object          con, item;
    int             i;

    ::reset();
    con = present("wall", this_object());
    inv = all_inventory(con);
    if( sizeof(inv) != 1) {
	for(i=sizeof(inv)-1; i>=0; i--)destruct(inv[i]);
	if (item = new(__DIR__"npc/obj/luwei")) {
	    if (!item->move(con))
		destruct(item);
	}
    }
}
