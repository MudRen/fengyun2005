#include <ansi.h>
#include <room.h>
inherit ROOM;

string *marryfood_names=({
  YEL"香酥花生"NOR,HIW"奶油瓜子"NOR,HIG"碧螺春卷"NOR,
  HIC"香片蒸鱼"NOR,HIW"麻辣手撕鸡"NOR,HIW"豉汁蒸鳝"NOR,YEL"白灼大虾"NOR,
  WHT"水晶虾饺"NOR,HIY"黄金花姿蟹钳"NOR,YEL"琵琶豆腐"NOR,
  HIG"翡翠玉带虾球"NOR,RED"蚝油肉片"NOR,HIW"四喜豆腐"NOR,HIY"北京烤鸭"NOR,
  YEL"叫花鸡"NOR,HIR"鱼香肉丝"NOR,HIW"白斩鸡"NOR,WHT"咸水鸭"NOR,YEL"狗不理包子"NOR,
  RED"麻辣鸡丁"NOR,HIR"夫妻肺片"NOR,WHT"清蒸海鲭斑"NOR,YEL"南乳脆皮鸡"NOR,
  YEL"红绕双喜大生翅"NOR,GRN"瑶柱扒双宝蔬"NOR
});
//美满姻缘饭  幸福伊府面  百年好合  永结同心  白发齐眉 

string *food_names=({
  MAG"西湖醋鱼"NOR,YEL"越王金钩翅"NOR,YEL"鸿图海皇大生翅"NOR,
  HIC"香片蒸鱼"NOR,HIW"麻辣手撕鸡"NOR,HIW"豉汁蒸鳝"NOR,
  HIY"黄金花姿蟹钳"NOR,HIY"粉蒸肉"NOR,RED"麻辣火锅"NOR,
  HIG"君子好逑汤"NOR,RED"蚝油肉片"NOR,HIW"四喜豆腐"NOR,HIY"北京烤鸭"NOR,HIR"重庆火锅"NOR,
  YEL"叫花鸡"NOR,HIR"鱼香肉丝"NOR,HIW"白斩鸡"NOR,WHT"咸水鸭"NOR,YEL"狗不理包子"NOR,
  RED"麻辣鸡丁"NOR,HIR"夫妻肺片"NOR,HIR BLK"麻辣臭豆腐"NOR,YEL"广式烧鸭"NOR
});

string *wine_names=({
  WHT"米酒"NOR, GRN"竹叶青"NOR, YEL"绍兴酒"NOR, HIR"女儿红"NOR,
  WHT"茅台酒"NOR,RED"桂花酒"NOR,RED"陈年花雕"NOR,WHT"五粮液"NOR,
  HIR"杜康酒"NOR,WHT"烧刀子"NOR,RED"葡萄酒"NOR,HIW"透瓶香"NOR,HIG"百草酒"NOR,
  HIR"状元红"NOR,GRN"梨花酒"NOR,BLK"酒鬼酒"NOR
});

string *water_names=({
  HIG"龙井茶"NOR, RED"普洱茶"NOR, GRN"庐山云雾"NOR, HIG"君山银针"NOR,
  GRN"碧螺春"NOR,HIG"乌龙茶"NOR,GRN"铁观音"NOR
});

string *cup_names=({
  MAG"紫砂盅"NOR, WHT"水晶盏"NOR, HIW"搪瓷杯"NOR, GRN"翡翠杯"NOR,
  HIY"象牙杯"NOR,MAG"紫檀杯"NOR,YEL"鎏金杯"NOR,WHT"琉璃杯"NOR,HIG"青铜爵"NOR,
  WHT"羊脂白玉杯"NOR,HIW"夜光杯"NOR,YEL"犀角杯"NOR,RED"古藤杯"NOR,HIY"象牙杯"NOR
});

varargs protected void create_food(string nmstr, string* idlist)
{
    object obj,table;

    obj = new(__DIR__"obj/food");
    obj->set_name(nmstr, idlist);
    obj->set("long", GRN+"一盘热气腾腾, 香喷喷的"+nmstr+"。\n"+NOR);
    table = present("table", this_object());
    obj->move(table);
}

varargs protected void create_water(string nmstr, string* idlist, string cup)
{
    object obj,table;

    obj = new(__DIR__"obj/water");
    obj->set_name(cup, idlist);
    obj->set("long", YEL+"一杯热热的" + nmstr + "。\n" + NOR);
    obj->set("liquid/name", nmstr);
    table = present("teatable", this_object());
    obj->move(table);
}

varargs protected void create_wine(string nmstr, string* idlist, string cup)
{
    object obj,table;

    obj = new(__DIR__"obj/wine");
    obj->set_name(cup, idlist);
    obj->set("long", RED+"一杯醇正的" + nmstr + "。\n" + NOR);
    obj->set("liquid/name", nmstr);
    table = present("bar", this_object());
    obj->move(table);
}

void create()
{
    set("short", HIG"玫瑰宴厅"NOR);
    set("long", @LONG
进门绕过一道淡黄绸屏风，迎面墙上挂着一副『花开富贵』图，鲜嫩欲
滴，花瓣轻分，似有香气盈室。厅内陈列奢华，正中央一张雕花楠木青漆嵌
玉大圆桌，四周十二张镶银象牙扶手红木椅，杯碗勺箸，入眼生辉。
这里便是千金楼对面的牡丹宴会厅，桌上平铺着一份菜单(menu)。
LONG );
    set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"huanyun3",
      ]));
    set("no_sleep_room",1);
    set("item_desc", ([
	"menu": @TEXT

本店各式酒席, 欢迎惠顾：

        order marry:    结婚喜宴        (50两黄金)

        order party:    英雄大宴        (100两黄金)

        order end:      结束宴会

TEXT
      ]) );

    set("no_fight",1);
    set("no_magic",1);
    set("NONPC",1);      
    set("coor/x",-40);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");

    setup();

}

void init()
{
    object me;

    add_action("do_order", "order");
    add_action("do_get", "get");
}
int do_get(string arg)
{
    if (!arg)	return 0;
    if (arg=="all" && query("order_owner")){
	write("难道你是猪。。下凡，这么大的胃口？\n");
	return 1;
    }
    return 0;
}


int do_order(string arg)
{
    object me, env, table;
    object* oblist;
    string name,msg;
    int idx,size,i;

    me = this_player();
    env = this_object();
    name = query("order_owner");
    if (name && (arg == "end") && (name == me->query("id"))) {
	msg = "牡丹厅的宴会结束了  !!!\n";
	CHANNEL_D->do_sys_channel("info",msg);
	delete("order_owner");
	delete("order_type");
	oblist = all_inventory(env);
	for(idx=0; idx<sizeof(oblist); idx++) {
	    if (!objectp(oblist[idx]))
		continue;
	    if (userp(oblist[idx]))
		continue;
	    destruct(oblist[idx]);
	}
	return 1;
    }
    if (name)
	return notify_fail("这里已经被人包租了.\n");
    if (arg == "marry") {
	if (me->query("deposit") < 500000) return notify_fail("你的银行存款不够\n"); //100g
	me->add("deposit",-500000);
	tell_object(me,HIG"宴会共计五十两黄金，谢谢惠顾！\n"NOR);
	msg = me->name() + "现在在千金楼牡丹厅举行订婚酒宴了！！！恭喜！恭喜！\n";

	table = new("/d/fy/obj/table");
	table ->move(environment(me));
	table = new("/d/fy/obj/bar");
	table ->move(environment(me));
	table = new("/d/fy/obj/teatable");
	table ->move(environment(me));

	create_food(CYN"美满姻缘饭"NOR, ({ "meal" }) );
	create_food(YEL"幸福伊府面"NOR, ({ "noodle" }) );
	create_food(WHT"百年好合"NOR, ({ "meal" }) );
	create_food(HIR"永结同心"NOR, ({ "meal" }) );
	create_food(HIW"白发齐眉"NOR, ({ "meal" }) );
	create_food(RED"喜糖"NOR, ({ "candy" }) );
	create_food(RED"喜糖"NOR, ({ "candy" }) );
	create_food(RED"喜糖"NOR, ({ "candy" }) );
	create_food(RED"喜糖"NOR, ({ "candy" }) );
	create_food(RED"喜糖"NOR, ({ "candy" }) );

	size = sizeof(marryfood_names);
	for(i=0;i<20;i++)  {
	    create_food(marryfood_names[random(size)],({"food"}));
	}

	size = sizeof(wine_names);
	for(i=0;i<15;i++)  {
	    create_wine(wine_names[random(size)],({"wine"}),cup_names[random(sizeof(cup_names))]);
	}

	size = sizeof(water_names);
	for(i=0;i<5;i++)  {
	    create_water(water_names[random(size)],({"tea"}), cup_names[random(sizeof(cup_names))]);
	}

    } else if (arg == "party") {

	if (me->query("deposit") < 1000000) return notify_fail("你的银行存款不够\n"); //100g
	me->add("deposit",-1000000);
	tell_object(me,HIG"宴会共计一百两黄金，谢谢惠顾！\n"NOR);
	msg = me->name() + "现在在千金楼牡丹厅宴请各路英雄豪杰!大家快来白吃白拿啊！\n";

	table = new("/d/fy/obj/table");
	table ->move(environment(me));
	table = new("/d/fy/obj/bar");
	table ->move(environment(me));
	table = new("/d/fy/obj/teatable");
	table ->move(environment(me));

	create_food(CYN"问鼎天下"NOR, ({ "meal" }) );
	create_food(BLK"妙计定国"NOR, ({ "meal" }) );
	create_food(HIC"二十四桥明月心"NOR, ({ "meal" }) );
	create_food(HIW"清风伴雪飞"NOR, ({ "meal" }) );
	create_food(HIG"翡翠玉带虾球"NOR, ({ "meal" }) );


	size = sizeof(food_names);
	for(i=0;i<30;i++)  {
	    create_food(marryfood_names[random(size)],({"food"}));
	}

	size = sizeof(wine_names);
	for(i=0;i<15;i++)  {
	   create_wine(wine_names[random(size)],({"wine"}),cup_names[random(sizeof(cup_names))]);
	}

	size = sizeof(water_names);
	for(i=0;i<5;i++)  {
	    create_water(water_names[random(size)],({"tea"}), cup_names[random(sizeof(cup_names))]);
	}
    }
    else {
	return notify_fail("你要定什么酒席?\n");
    }
    CHANNEL_D->do_sys_channel("info",msg);
    set("order_owner", me->query("id"));
    set("order_type", arg);
    return 1;
}
int valid_leave(object me, string dir)
{
    if (me->query("id") != query("order_owner"))
	return 1;
    return notify_fail(RED + "先用 order end 结束宴会后才能离开。\n" + NOR);
}

