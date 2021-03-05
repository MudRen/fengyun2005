// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
int do_put(object me, object obj);
void create()
{
        set("short", "小酒肆");
        set("long", @LONG
傍着翠竹和石雕门坊是一个简陋的小酒肆，竹子搭成的架子，茅草做顶，一根
细竹竿挑着一面小旗，上面是斗大的酒字，下面有一个木箱。篷下摆着几张简陋的
长凳和木桌供游人休息。酒肆旁翠竹边埋着一个大缸，阵阵酒香随风飘来。奇怪的
是这里没有人看管，游客取食完后，都会自动往木箱中放（ｆａｎｇ）钱。      
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"shanmen",
	]) );
	set("item_desc", ([
		"stool" : "简单的小木头长板凳。\n",
		"长凳" : "简单的小木头长板凳。\n",
		"木箱" : "木箱上有一个开口，你可以放（ｆａｎｇ）钱进去。\n",
		"box" : "木箱上有一个开口，你可以放（ｆａｎｇ）钱进去。\n",
	]) );
    set("outdoors", "huangshan");
	set("mantou_amount", 50);
	set("jiu_amount", 70);
	set("coor/x",0);
	set("coor/y",5);
	set("coor/z",0);
	setup();
}

void init() {
	add_action("do_look", "look");
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
	add_action("do_tou", "fang");
}

int do_tou(string arg){
	string item;
	object me, obj, obj2/*, *inv*/;
	int amount;
	me = this_player();
	
	if(!arg) {
		return notify_fail("你要投什么？\n");
	}
	if(me->is_fighting() || me->is_busy()){
		return notify_fail("你正在忙！\n");
	}
	sscanf(arg, "%s", item);

    if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) ) {
 			return notify_fail("你身上没有这样东西。\n");
   		}
  		if(obj->query("money_id") != "silver" && obj->query("money_id") != "gold" 
				&& obj->query("money_id") != "coin" ){
     		return notify_fail( "还是投钱吧！\n");
   		}
        if( amount < 1 )
                return notify_fail("东西的数量至少是一个。\n");
        if( amount > obj->query_amount() )
                return notify_fail("你没有那麽多的" + obj->name() + "。\n");
        else if( amount == (int)obj->query_amount() )
                return do_put(me, obj);
        else {
                obj->set_amount( (int)obj->query_amount() - amount );
                obj2 = new(base_name(obj));
                obj2->set_amount(amount);
                return do_put(me, obj2);
        }
    }
	if( !objectp(obj = present(item, me)) ) {
    	return notify_fail("你身上没有这样东西。\n");
    }
    if(obj->query("money_id") != "silver" && obj->query("money_id") != "gold" 
		&& obj->query("money_id") != "coin" ){
        return notify_fail( "还是投钱吧！\n");
    }
   return do_put(me, obj);
}

int do_put(object me, object obj){
    int i, j, value;
    message_vision("$N将" + obj->name() + "投入了木箱。\n", me);
    i = obj->query("base_value");
    j = obj->query_amount();
    value = i*j;
    if(value < 10) {
    	message("vision", me->name()+"趁人不注意悄悄塞了几个铜板进去。\n", environment(me), me);
    }
    if(value > 20000 && !me->query("marks/慷慨")) {
    	me->set("marks/慷慨", 1);
    }	
    destruct(obj);
    return 1;
}
	
int do_look(string arg) {
	object me;
	int i, j;
	
	me = this_player();
	i = query("mantou_amount");
	j = query("jiu_amount");
	if( !arg || arg != "table" && arg != "木桌" && arg != "dagang" 
&& arg != "酒缸" && arg != "大缸") return 0;
	if(arg == "table" || arg == "木桌") {
		if (i > 0) {
			write("桌子上面有一竹篮，里面有些小白面馒头，看来是可以吃（ｅａｔ　ｍａｎｔｏｕ）的。\n");
		} else {
			write("桌子上面有一竹篮，里面只剩下了一些馒头渣。\n");
		}	
		me->set_temp("know_mantou", 1);
	} else if (arg == "dagang" || arg == "酒缸" || arg == "大缸") {
		if (j > 0) {
			write("酒缸里装着些米酒，旁边挂了个竹舀，酒香扑鼻。你可以喝（ｄｒｉｎｋ　ｗｉｎｅ）。\n");
		} else {
			write("酒缸已经空了，但你仍然可以闻到浓浓得酒香。\n");
		}
		me->set_temp("know_jiu", 1);
	}
	return 1;
}	

int do_eat(string arg) {
	object me;
	int i;
	
	me = this_player();
	i = query("mantou_amount");
	
	if( !arg || arg != "man tou" && arg != "馒头" && arg != "mantou" ) return 0;
	if( me->is_fighting()) return notify_fail("你现在不能吃。\n");
	if( i > 0 && me->query_temp("know_mantou")) {
		if (me->query("food") >= me->max_food_capacity() ) {
			write("你已经吃饱了，实在吃不下了。\n");
			message("vision", me->name() + "面有难色的看着面前桌子上的馒头。\n",
					environment(me), me);
			return 1;
		} else {
			if(me->is_busy()) return notify_fail("你现在忙，不能吃。\n");
			message_vision("$N拿起一个小馒头，三两口吞到了肚子里。\n", me);
			me->start_busy(2);
		}
		add("mantou_amount", -1);
		me->add("food", 20);
	} else if( i =0 && me->query_temp("know_mantou")) {
		write("已经没有馒头了！\n");
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
	i = query("jiu_amount");
	
	if(!arg || arg != "wine" && arg != "米酒") return 0;
	if(me->query("water") >= me->max_water_capacity())
			return notify_fail("你似乎并不渴。\n");
	if(me->is_fighting()) return notify_fail("你现在不能喝。\n");
	if(me->is_busy()) return notify_fail("你现在忙，不能喝。\n");
	if (i > 0 && me->query_temp("know_jiu")) {
		message_vision("$N拿起竹舀，弯下腰，在酒缸里舀了一大勺酒，咕咚咕咚灌了下去。\n",me);
		me->start_busy(2);
		add("jiu_amount", -1);
		me->add("water",10);
		me->apply_condition("drunk", me->query_condition("drunk") + 4 + random(6));
	} else if( i = 0 && me->query_temp("know_jiu")) {
		write("酒缸已经空了。\n");
		message("vision", me->name() + "探头往酒缸里看了看。\n", environment(me), me);
	} else {
		return 0;
	}
	return 1;
}