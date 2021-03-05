// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "映景明湖");
    set("long", @LONG
进山这许多天来，第一次看见湖水的欣喜刹时间满溢心头。近到湖边捧起
一口清甜甘冽的水，你简直不忍心将之饮入腹中。一恍神间，只见掌心盈盈的
水突地起了波动，你讶异地望向湖心，只见湖水波光变幻，倒映着的俨然是风
云城内光景。
LONG
NOR
        );
	set("objects", ([


	]));
	set("item_desc", ([
	"湖水":"你可以借助映景明湖的魔力来观看你想要知道的事情(scry)。\n",
	"湖":"你可以借助映景明湖的魔力来观看你想要知道的事情(scry)。\n",
	"lake":"你可以借助映景明湖的魔力来观看你想要知道的事情(scry)。\n"

	]) );
	set("exits",([
  		"northdown" : "peak7",
  		"westdown" : "peakx",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

void init() {

object ob;
object me = this_player();
	::init();



	if (REWARD_D->riddle_check(me,"韶光虚掷") == 1) 
	{
		ob=new(__DIR__"npc/dizi");
		ob->set("name","张三");
		ob->move(this_object());
		ob=new(__DIR__"npc/dizi");
		ob->set("name","李四");
		ob->move(this_object());
		ob=new(__DIR__"npc/dizi");
		ob->set("name","王五");
		ob->move(this_object());
		ob=new(__DIR__"npc/dizi");
		ob->set("nickname",HIR"血羽天魔"NOR);
		ob->set("title","西方魔教 "MAG"天魔坛主"NOR);
		ob->set("name","穆长风");
		ob->set("id","master mu");
		ob->move(this_object());

		me->set_temp("disable_inputs",1);

		call_out("do_ggyy",2,me,ob,0);


	}


	add_action("do_scry","scry");
}



void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$n正焦急地左右踱步，见$N进来，脸上微露喜色。
$n道：昭光，你到哪里去了？为师不是吩咐你上山之后，尽速来此处会合么？\n",

"$n说道：也罢，也罢，来了就好。
$n说道：金狮长老两个时辰前飞鸽传书道岱庙有变，"WHT"寒萸刀鞘"CYN"遭人窃走。",

"$n道：为师须得速速赶回，此处"WHT"饮血平寇"CYN"、共谋扫荡倭人之事，便交由你一力主持。\n",
"$n转头吩咐众弟子道：你们且小心尾随在副坛主后，若有战事再出面便是。
$n嘿嘿冷笑道：否则那些中原名门，又该当咱们是什么十恶不赦之徒了。\n",

"$n给$N一盒西迟化生散，说道：听闻中原武林这次颇来了几个不凡的人物，昭光你可要千万小心，切莫托大。",
"$n拍拍$N的肩膀，纵身而起，转瞬间化作一道青烟消失在山林之间。
众弟子向$N躬身一礼，亦四散离去。\n",
});
	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];


	message_vision(CYN+msg+"\n"NOR,me,target);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{

	tell_object(me,HIY"你的任务改变了！\n"NOR);

	me->set("quest/short", WHT"离开"CYN+"映景明湖"+WHT""NOR);
	me->set("quest/location", "映景明湖");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());


		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		REWARD_D->riddle_set(me,"韶光虚掷",2);
		destruct(target);
		target=new("/d/phoenix/npc/obj/cyan_drug");
		target->move(me);
		me->set_temp("disable_inputs",0);
		if (present("dizi"))
			destruct(present("dizi"));
		if (present("dizi"))
			destruct(present("dizi"));
		if (present("dizi"))
			destruct(present("dizi"));
		return;
	}
	return;
}


// inventory messages.
string inventory_look(object obj, int flag) {
    string str, desc;
    object me, left, right;

    str = obj->short();
    if(obj->query("equipped")) {
        if(!desc = obj->query("armor_worn")) {
            if(!desc=obj->query("weapon_wielded")) {
                desc = "√";
            } else {
                me = environment(obj);
                left = me->query_temp("left_hand");
                right = me->query_temp("right_hand");
                if(obj == left && obj == right) {
                    desc = "双手" + desc + "着";
                } else if(obj == right) {
                    desc = "右手" + desc + "着";
                } else {
                    desc = "左手" + desc + "着";
                }
            }
        }
        str = desc + str;
    } else if(!flag) {
        str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
                "怀藏" : "  ") + str;
    } else {
        return 0;
    }
    
    return str;
}

int do_scry(string arg)
{
	object me = this_player();
	object obj;

    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;

	if (!arg)
		return notify_fail("你想寻找什么？\n");

	if (me->query_temp("timer/big_cmd")+2 > time())
		return notify_fail("映景明湖中的水波还没有彻底平静，再等一等吧。\n");
	else
		me->set_temp("timer/big_cmd",time());

	me->add("sen",-30);

	obj = find_living(arg);
	if (!obj)
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");
	if (!environment(obj))
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");
	if (userp(obj))
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");
	 if (obj->query("race")=="元素")
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");


	message_vision("映景明湖水波荡漾变幻，又慢慢归于平静。\n",me);
	message_vision("湖中倒映出了"+obj->name()+"的身影。\n",me);

	str = obj->long();
    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

    if((string)obj->query("race")=="人类" && intp(obj->query("age")))
    {
        if(userp(obj))
		{
            str +=  sprintf("%s看起来象%s多岁的%s人。\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10), obj->query("national"));
		    } else 
			{
            str += sprintf("%s看起来约%s多岁。\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10));
			  }
    }

    // current kee status.
    if(obj->query("max_kee")) {
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
                / (int)obj->query("max_kee")) + "\n";
    }
    
    // inventory message.
    if(obj->query("race") == "人类") {
        str += pro + (obj->is_naked() ? "赤身裸体。\n" : "");
    }
    inv = all_inventory(obj);
    if(sizeof(inv)) {
        inv = map_array(inv, "inventory_look", this_object(), (obj == me || obj->is_corpse()) ? 0 : 1 );
        inv -= ({ 0 });
        if(sizeof(inv)) {
            str += sprintf("%s\n", implode(inv, "\n  "));
        }
    }
    // tatoo print
    if (obj->query_temp("body_print") ) str += obj->query_temp("body_print")+ "\n";

    
    // send out message
    message("vision", str + "\n", me);
	return 1;
}




int	valid_leave(object who, string dir)
{
	object me;
	me = who;
		if (REWARD_D->riddle_check(me,"韶光虚掷") == 3) 
		{
			return notify_fail("你的去路被饭冢挡住了！\n");
		}

		if (REWARD_D->riddle_check(me,"韶光虚掷") == 2) 
		{
			REWARD_D->riddle_set(me,"韶光虚掷",3);
			who=new(__DIR__"npc/j1");
			who->move(this_object());
			message_vision(HIR"一道人影突自湖边的大树上飞掠而下，挡住$N的去路。\n"NOR,me);
			message_vision(HIR"$N道：你们神教、应许宗主清荡中原，背义弃信，不可原谅！
$N道：哼、老头本事高，你，不行的，受死吧！\n\n"NOR,who);	// not typo.
			who->kill_ob(me);
			me->kill_ob(who);
			return notify_fail("\n");
		}

	return ::valid_leave(who,dir);
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


