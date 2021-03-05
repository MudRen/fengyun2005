
inherit ROOM;
int b_shoot();
void create()
{
        set("short", "竹峪");
        set("long", @LONG
此处遍生青竹，满谷翠绿，生机盎然，阵阵山风吹来，只听沙沙竹叶声，不
见人踪。竹峪两边峰岭相接，山势连绵起伏，沟壑纵横，奇石林立。山间小路蜿
蜒曲折，路旁修竹婷婷随风摇曳，一片宁静。
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"xiaojing",
  		"westup" : __DIR__"changpu",
		"eastup" : __DIR__"ziwei",
	]));
   	set("shoots_amount", 3);
   	set("bamboo_amount", 3);
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",10);
	set("coor/z",-30);
	setup();
}

void init(){
	if(NATURE_D->get_season() == 1 && NATURE_D->get_weather() == "小雨") {
		tell_object(this_player(), "雨中，只听见竹林之中不断传来哔哔啵啵的声音。\n");
	}
	add_action("do_search", "search");
	add_action("do_pick", "pick");
}
 
int do_pick(string arg)
{
    object bamboo;
    if ( !arg && arg != "bamboo" && arg != "竹子" && arg != "zhuzi")
            return notify_fail("你要折什么？\n");
    if((int) query("picked") <= 2)
    {
            write("你折了一根青青的竹子，小心的放在怀里。\n");
            bamboo = new("/d/taoyuan/obj/bamboo");
            bamboo->move(this_player());
            add("picked",1);
            return 1;
    }
    else
    write("竹子已经被人折光了！！\n");
    return 1;
}

int do_search(){
	message_vision("$N仔细的在竹林地上寻找。\n", this_player());
	if(NATURE_D->get_season() == 1 && query("shoots_amount") >= 0) {
		tell_object(this_player(), "你发现一根嫩嫩的竹笋刚刚拱出地面。可以把它刨出来。\n");
		this_player()->set_temp("marks/found_shoot", 1);
	} else {
		tell_object(this_player(), "你什么也没有发现。\n");
	}
	return 1;
}

int dig_notify() {
	object me, item;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(me->is_busy()) { 
	    write("你现在正在忙！\n");
	    return 1;
	}
	if(me->is_fighting()) return 0;
	if(NATURE_D->get_season() != 1 || !me->query_temp("marks/found_shoot")) {
	    message_vision("$N用力往地上一刨，不过除了盘绕的竹根外什么也没有发现。\n", me);
	} else {
		if (query("shoots_amount") >= 0) {
    		message_vision("$N用力往地上一刨。\n", me);
        	message_vision("一根嫩嫩的竹笋露了出来。\n", me);
        	me->delete_temp("marks/found_shoot");
        	item = new(__DIR__"obj/bshoot");
        	if(objectp(item)) {
        		item->move(this_object());
        		add("shoots_amount", -1);
			}
		}
	}
	me->start_busy(1);
}

void reset(){
	::reset();
	set("shoots_amount", 3);
	delete("picked");
}
