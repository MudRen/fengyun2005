// ghost.c

#include <ansi.h>
inherit NPC;

/*int	*range = ({
		2,3,5,7,11,17,25,35,45,55,				// L1 - 10
		66,77,89,102,115,129,143,158,174,191,			// L11 - 20
		209,228,248,270,293,319,346,376,406,438,		// L21 - 30
		470,504,538,573,608,644,680,718,757,797,		// L31 - 40
		837,879,921,964,1008,1052,1098,1144,1192,1240,		// L41 - 50
		1289,1338,1388,1438,1490,1542,1596,1650,1706,1764,	// L51 - 60
		1823,1882,1942,2003,2066,2129,2194,2259,2326,2395,	// L61 - 70
		2464,2536,2609,2684,2761,2841,2921,3003,3085,3168,	// L71 - 80
		3251,3335,3419,3504,3589,3676,3763,3852,3941,4031,	// L81 - 90
		4123,4216,4311,4407,4504,4602,4700,4800,4900,5000,	// L91 - 100
	});
*/

int ask_me();
int annie_drug()
{
	object me = this_player();

	if (me->query_temp("annie/find_herb/普生") 
		&& me->query_temp("annie/find_herb/百里灵") 
		&& me->query_temp("annie/find_herb/万小春") 
		&& me->query_temp("annie/find_herb/万春流") 
		&& me->query_temp("annie/find_herb/百里雪") 
		&& me->query_temp("annie/find_herb/叶星士")	)
	{

		message_vision(query("name")+"嘿嘿一笑道：竟然无人识得此草，都是浪得虚名、浪得虚名啊。\n",me);
		if (REWARD_D->riddle_check(me,"天灵翡翠") != 3
			&& REWARD_D->riddle_check(me,"天灵翡翠") != 4)
		{
			message_vision(query("name")+"说道：这药材给你也是无用之物，我也懒得指点你了。\n",me);
			return 1;
		}
		else
		{
			message_vision(query("name")+"道：我曾听二弟提起此物，只是他如今已在九泉之下．．．\n",me);
			REWARD_D->riddle_set(me,"天灵翡翠",4);
			return 1;
		}
	}
	message_vision(query("name")+"挥挥手：去，问别人去，别来烦老夫！\n",me);
	return 1;
}

void create()
{
        set_name("梅大先生", ({ "mei da", "meida"}) );        
        set("title",WHT"礼到病除"NOR);
        set("age", 65);
        set("long","一个峨服高冠的老人，正在指挥着两个童子洗树上的冰雪，他就是七妙人中
梅家二老的老大。梅大先生的武功如何，从来没人知道，因为从来没人敢和
他动过手。梅大先生的医术据说可以起死回生，就连小李飞刀李寻欢当年也
受过他的恩惠。江湖中谁不会有个闪失？谁又敢得罪这一位救星？不过，梅
大先生从不白替人看病，即使是搭个脉也是要收钱的。如果你真的有什么疑
难杂症，可以向他打听治病的事儿。\n");
        
        set("combat_exp", 8000000);
        set("inquiry", ([
        		"明烟草" : 	(: annie_drug :),
        		"受伤" : 	(: ask_me :),
             	"hurt" :	(: ask_me :),
             	"recover":	(: ask_me :),
             	"cure":	(: ask_me :),
             	"治病":		(: ask_me :),
   	]));
    	      
        setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init() {
	add_action("do_cure","cure");
	::init();
}



int ask_me(){
//	int exp,cost;
	object me;
	int level;
	
	me = this_player();
	if (!me->query("attr_apply/strength")
		&& !me->query("attr_apply/intelligence")
		&& !me->query("attr_apply/composure")
		&& !me->query("attr_apply/agility")
		&& !me->query("attr_apply/constitution")
		&& !me->query("attr_apply/karma")
		) {
		message_vision(CYN"梅大先生一伸手搭住$N的脉门，冷冷地说：无病无灾，敢情是消遣老夫来着？\n"NOR,me);
		me->set_temp("marks/cheat_meida",time());
		return 1;
	}
		
	level = me->query("level");
	
	message_vision(CYN"梅大先生左左右右，上上下下地打量了$N几眼说：“治是能治，但老夫从不做赔本的买卖。”\n"NOR,me);
	tell_object(me, WHT"恢复一点属性需要"+chinese_number(level*2)+"两银子，你是否愿意？\n"NOR);
	tell_object(me, WHT"如果你在钱庄有足够的存款，输入<cure 属性名>\n"NOR);
	return 1;
}
	
int do_cure(string arg) {
	
	int /*exp,*/ level, cost;
	object me;
	
	string cure;
	
	me = this_player();
	if (!arg)
		return notify_fail("格式：cure　＜内容＞
其中＜内容＞为才智 caizhi、体质 tizhi、力量 liliang、速度 sudu、
运气 yunqi、定力 dingli	\n");
		      	
		switch (arg) {
		
		case "才智" :
		case "int":
		case "intelligence":
		case "caizhi" :	cure = "intelligence"; 	break;			
        
        case "力量" :
        case "str":
        case "strength":
        case "liliang": cure = "strength"; 	break;			
        
        case "体质" :
        case "con":
        case "constitution":
        case "tizhi" :	cure = "constitution"; 	break;			
        
        case "运气" :
        case "kar":
        case "karma":
        case "yunqi" :	cure = "karma"; 	break;			
        
        case "速度" :
        case "agi":
        case "agility":
        case "sudu" :	cure = "agility"; 	break;			
        
        case "定力" :
        case "cps":
        case "composure":
        case "dingli":	cure = "composure"; 	break;			
        
        default :
			return notify_fail("没有这个属性。\n");
	}
	
	if (!me->query("attr_apply/"+cure) || me->query("attr_apply/"+cure)>=0)
		return notify_fail("你的"+arg+"没有损伤。\n");
	
	level = me->query("level");
	cost = level * 200;

	if (me->query("deposit")< cost)
		return notify_fail("你的钱庄存款不够"+ chinese_number(level*2) +"两银子。\n");

	if (cost < 0)	cost= 0;
			
	me->add("deposit",-cost);
		
	message_vision(YEL"梅大先生微微一笑，将一粒朱红色的药丸塞入$N口中。。。。\n"NOR,me);
	tell_object(me,WHT"你只觉刺喉有如刀割，药气冲鼻，浑身却舒坦了许多。\n"NOR);
	me->add("attr_apply/"+cure,1);
	return 1;
}
	

int accept_object(object who, object item){
	if (item->query("value") > 10000) {
		message_vision("梅大先生笑嘻嘻地说：“好、好，不送。”\n",who);
		who->delete_temp("marks/cheat_meida");
		return 1;
	}
	message_vision("梅大先生对$N说：“你的命就这么不值钱？”\n",who);
	return 0;
}