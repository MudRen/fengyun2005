// mind_beast.c

inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
    	set_name("白骏马", ({ "white horse" }) );
		set("race", "家畜");
		set("gender", "雄性");
		set("age", 3);
    //set("long", "一匹皮毛黑亮的野马，自由自在的撒蹄飞奔着，不知是否可以驯服（ｘｕｎｆｕ）。\n");
		set("long",(: horsedesc :));
        set("max_kee", 3000);
		set("max_gin", 3000);
		set("max_sen", 3000);
		set("int",40);
		set("cor",80);
		set("str",50);
		set("attitude", "peaceful");
		
        set("chat_chance", 1);
        set("chat_msg", ({
        "白骏马＂咴～～咴咴＂地仰天长了几声\n",
        }) );
        set("combat_exp", 5000000);
		set_temp("apply/attack", 300);
		set_temp("apply/dodge",300);
		set_temp("apply/damage",200);
	
		setup();
}
void init()
{
	::init();
	add_action("do_xunfu","xunfu");
	add_action("do_ride","ride");
}
string horsedesc()
{
	object me;
	me = this_player();
	if (me ->query("marks/驯服_白骏马"))
	{	
		return "怒江无船无人，你只有骑上（ride）这野马跃过怒江！";
	}
	return "一匹皮毛纯白的野马，自由自在的撒蹄飞奔着，不知是否可以驯服（ｘｕｎｆｕ）。\n";
}


int do_xunfu(string arg)
{
	object me;
	me = this_player();
	
	if (arg != "白骏马" && arg != "white horse" && arg != "野马")
	{	
		tell_object( me, "你想要驯服什么？\n");
		return 1;
	}
	
	if (me->query("marks/驯服_白骏马"))
	{
		tell_object(me, "白骏马在你身边蹭来蹭去，非常高兴。\n");
		return 1;
	}
	
	message_vision("$N长嘶一声，扬尾踏足，乱踢狂奔，硬是要把$n扔下来。。。 \n",this_object(),me);
	if (me->query_skill("dodge",1)>=50 
		&& me->query("kar")>=(20+random(10))
		&& me->query_skill("animal-training",1)>=100)
	{
        message_vision(HIC"$n紧紧抓住马鬃，无论$N如何撩蹄打撅，稳如泰山般附在马背。\n "NOR,this_object(),me);
        message_vision("$N终于安静了下来，驯服地喘着粗气。。\n$n满意地拍了拍$N的头，从马上跃了下来。\n",this_object(),me);
		me->set("marks/驯服_白骏马",1);
	}else
	{
		message_vision("$n终于不支，从$N背上摔了下来。\n",this_object(),me);
		me->unconcious();
	}
	return 1;
}

int do_ride(string arg)
{
	object me, room;
	me = this_player();
	
	if (arg != "白骏马" && arg != "white horse" && arg != "野马")
	{	
		tell_object( me, "你想要骑什么？\n");
		return 1;
	}
	
	if (!me->query("marks/驯服_白骏马"))
	{
		message_vision("白骏马长嘶一声人立而起，$n慌慌张张地倒退几步。\n",me);
		return 1;
	}
	
	if (me->is_busy())
	{
		tell_object(me,"你现在正忙。\n");
		return 1;
	}
	
	message_vision(HIC"\n$n骑上马背，仰天长啸一声，抱紧马颈，双腿夹紧马腹，用力一鞭。。 。\n\n"NOR,this_object(),me);
	message_vision(HIW"
$N凌空跃起，以一个动人心弦、超越了世间一切美态的姿势，颈后的黑鬃毛 
在山风中自由地飘扬，有若天马行空，在天空里划出一条美丽的弧线，再落下至 
远方的浓雾里。 \n\n"NOR,this_object(),me);
	if (REWARD_D->riddle_check(me,"生死怒江") == 1
		&& !REWARD_D->check_m_success(me,"生死怒江"))
	{
		me->perform_busy(2);
		room = find_object(__DIR__"obj/horseback");
		if (!room) room = load_object(__DIR__"obj/horseback");
		if (me->move(room))
			call_out("do_riding",2,me,environment(me),room, 2 );
		else
			tell_object(me," BUG, please report to wizard, no room.\n");	
		this_object()->move(VOID_OB);
	}	
	else
	{	
		me->move("/d/guanwai/nujiang");
		message_vision("$N宛若神祗，乘着白骏马从天而降。\n",me);
		message_vision("$N跃下马背，白骏马踏风而去。\n",me);
	}
	return 1;
}

string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = load_object(room);

	str = HIR BLK"\n耳边风声秫秫，白骏马在险峻的蜀道上飞奔。\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),

	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}


void do_riding(object me,object room,object env,int count)
{
	object room1;
	
	string *msg = ({
		"白骏马这一奔，半个时辰内没有放缓脚步，
	
	耳边风声秫秫，身畔白雾缭绕，你也不知道现在何处，只紧紧地抱住马颈。\n",
	
		"view/d/guanwai/shudao1",
		
		"view/d/guanwai/shudao1",
		
		"view/d/guanwai/shudao1",
		
		"\n\n
白骏马越奔越快，地势越走越高，
	
眼前浓雾忽散，一人一马，竟已奔到绝崖之上。
		
白骏马竭尽全力凌空跃起，但终于力所不至，悲嘶一声，坠入怒江。
	
在坠落的一刹那，白骏马后背拱起，四蹄奋张，积最后一丝力量将你弹起。\n",
	
	});

	if (!me || !env)
		return;
	if (!room)	
	{
		room = load_object(AREA_GUANWAI"yuema");
		tell_object(me,CYN"\n白骏马一阵狂奔，终于渐渐放慢脚步～～～～～～～～\n\n"NOR);
		me->move(room);
		destruct(env);	// destruct used carpet
		return;
	}
	if (count < sizeof(msg))
	{
		if (msg[count][0..3]=="view") // view room.. 
			message_vision(view(msg[count][4..sizeof(msg[count])-1]),me);
		else
			message_vision(WHT""+msg[count]+"\n"NOR,me);
		count ++;
		call_out("do_riding",2,me,room,env,count);
	}
	else
	{
		message_vision(HIR"

你大惊失色，但是，一切都已经太晚了，

水声如雷，水势如洪，你胸口越来越闷，再也无法透过气来。

。。。。。。

\n"NOR, me);		
		room1 = find_object(AREA_GUANWAI"river");
		if (!room1) room1 = load_object(AREA_GUANWAI"river");
		me->unconcious();
		me->move(room1);
		destruct(env);	
		destruct(this_object());
		return;
	}
}


