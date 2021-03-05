// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "茶园");
        set("long", @LONG
一间茶园，谈不上开阔，却足够雅致。进得门来，满目嫩绿，空气中也荡漾着
清雅芳馥的茶香，园中搁了几个石凳，一张石桌。上面有些小碟小盏，里面是些糕
点茶水，铁雪山庄的子弟们但凡渴了饿了，都可到这儿随意食用。
LONG
        );
    	set("exits", ([ 
        	"east" : __DIR__"bamboo_hall",
	]) );
	set("item_desc", ([
	        "stool" : "一张石凳。\n",
	        "石凳" : "一张石凳。\n",
	        "table" : "一张石桌，上面放着些点心茶水。\n",
	        "石桌" : "一张石桌，上面放着些点心茶水。\n",
	        "小盏" : "一个精致的茶盏。\n",
	        "teacup" : "一个精致的茶盏。\n",
	]) );
    	set("outdoors", "resort");
    	set("gao_amount", 70);
    	set("tea_amount", 70);
	set("coor/x",-10);
	set("coor/y",-120);
	set("coor/z",0);
	setup();
}

void init() {
	add_action("do_look", "look");
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
}

int do_look(string arg) {
	object me;
	int i, j;
	
	me = this_player();
    	i = query("gao_amount");
    	j = query("tea_amount");
    	if( !arg || arg != "table" && arg != "石桌" && arg !="小盏" && arg!= "teacup" ) 
    		return 0;
    	if(arg == "table" || arg == "石桌") {
		if (i > 0) {
            		write("石桌上有几盘精致的小碟，里面有些桃酥糕，可以吃（ｅａｔ）的。\n");
		} else {
            		write("石桌上面有几个小碟，里面只剩下了一些糕点残渣。\n");
		}	
        	me->set_temp("know_gao", 1);
    	} else if (arg == "小盏" || arg == "teacup" ) {
		if (j > 0) {
            	write("茶盏里盛满了碧螺春，还冒着清香的热气。你可以喝（ｄｒｉｎｋ）。\n");
		} else {
            	write("茶盏已空了，不过茶香犹在空气中荡漾。\n");
		}
        	me->set_temp("know_tea", 1);
	}
	return 1;
}	

int do_eat(string arg) {
	object me;
	int i;
	
	me = this_player();
    	i = query("gao_amount");
	
    	if( !arg || arg != "taosu gao" && arg != "桃酥糕" && arg != "gao" ) return 0;
	if( me->is_fighting()) return notify_fail("你现在不能吃。\n");
    	if( i > 0 && me->query_temp("know_gao")) {
		if (me->query("food") >= me->max_food_capacity() ) {
			write("你已经吃饱了，实在吃不下了。\n");
            		message("vision", me->name() + "面有难色的看着面前剩下的糕点。\n",
					environment(me), me);
			return 1;
		} else {
			if(me->is_busy()) return notify_fail("你现在忙，不能吃。\n");
            		message_vision("$N拿起一个桃酥糕，慢慢的品尝着。\n", me);
			me->start_busy(2);
		}
        	add("gao_amount", -1);
        	me->add("food", 100);
    	} else if( i =0 && me->query_temp("know_gao")) {
        	write("已经没有糕点了！\n");
	} else { 
		return 0;
	}
	return 1;
}

int do_drink(string arg)
{
	object me;
	int i;
	
	me=this_player();
    	i = query("tea_amount");
	
    	if(!arg || arg != "tea" && arg != "碧螺春") return 0;
	if(me->query("water") >= me->max_water_capacity())
		return notify_fail("你似乎并不渴。\n");
	if(me->is_fighting()) return notify_fail("你现在不能喝。\n");
	if(me->is_busy()) return notify_fail("你现在忙，不能喝。\n");
    	if (i > 0 && me->query_temp("know_tea")) {
        message_vision("$N轻轻捧起茶盏，耐心地品茗起来。\n",me);
		me->start_busy(2);
        	add("tea_amount", -1);
        	me->add("water",100);
    	} else if( i = 0 && me->query_temp("know_tea")) {
        	write("茶盏已经空了。\n");
        	message("vision", me->name() + "端起茶盏看了看。\n", environment(me), me);
	} else {
		return 0;
	}
	return 1;
}


void reset(){
	::reset();
	set("gao_amount", 70);
    	set("tea_amount", 70);
}

