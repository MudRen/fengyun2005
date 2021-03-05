inherit ROOM;
void create()
{
        set("short", "底舱");
        set("long", @LONG
底舱阴暗潮湿，腐朽扑鼻。和上舱的富丽豪华极不吻合。一盏阴暗的吊烛随着
船身的摇摆而发出吱吱声。四壁阴冷而滑腻，似乎还有水珠的渗出，舱顶上吊着半
段绳子。舱底冰冷，似乎可以感到湖水的流动。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"sr1",
  		"east" : __DIR__"sr2",
	]));
    set("item_desc", ([
    	"半段绳子" : "绳子的一头钉在舱顶的一块木板上，你似乎可以拉这绳子（ｐｕｌｌ　ｃｏｒｄ）。\n",
    	"rope" : "绳子的一头钉在舱顶的一块木板上，你似乎可以拉这绳子（ｐｕｌｌ　ｃｏｒｄ）。\n",
    	"绳子" : "绳子的一头钉在舱顶的一块木板上，你似乎可以拉这绳子（ｐｕｌｌ　ｃｏｒｄ）。\n",
    	"cord" : "绳子的一头钉在舱顶的一块木板上，你似乎可以拉这绳子（ｐｕｌｌ　ｃｏｒｄ）。\n",
    ]));
    set("objects", ([
        __DIR__"npc/prisoner" : 3,
    ]) );

	set("coor/x",-60);
	set("coor/y",15);
	set("coor/z",-10);
	setup();
}

void init(){
	add_action("do_pull", "pull");
}

int do_pull(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "cord" && arg != "绳子")) {
		return 0;
	}
	if(!query("exits/up")) {
		message_vision("$N用力一扯头顶上的绳子，一块木板翻开，露出向上的通路。\n", me);
		set("exits/up", __DIR__"eting");
		room = find_object(__DIR__"eting");
		if(!objectp(room)){
			room = load_object(__DIR__"eting");
		}
		room->set("exits/down", __DIR__"secret_room");
		call_out("close_path", 10);
	} else {
		message_vision("$N用力一扯头顶上的绳子，一块木板挡上了向上的通路。\n", me);
		delete("exits/up");
		room = find_object(__DIR__"eting");
		if(!objectp(room)){
			room = load_object(__DIR__"eting");
		}
		if(room->query("exits/down")){
			room->delete("exits/down");
		}
	}
	return 1;
}

void close_path()
{
	object sect;
	if( !query("exits/up") ) return;
	delete("exits/up");
	message("vision", "木板滑上挡住了向上的出口。\n", this_object());
	sect = find_object(__DIR__"eting");
	if(!objectp(sect)) {
		sect = load_object(__DIR__"eting");
	}
	sect->delete("exits/down");

}
