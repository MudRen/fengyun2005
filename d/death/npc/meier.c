// ghost.c

#include <ansi.h>
inherit NPC;

int ask_me();

int annie_drug()
{
	object me = this_player();

	if (REWARD_D->riddle_check(me,"天灵翡翠") == 4
		|| REWARD_D->riddle_check(me,"天灵翡翠") == 5)
	{
		message_vision(query("name")+"眯起眼来上上下下地打量着$N。\n",me);
		message_vision(query("name")+"点点头道：嗯，果然有诚心。\n",me);
		message_vision(query("name")+"说道：这明烟草么，天上地下，只得三株。\n",me);
		message_vision(query("name")+"说道：第一株在御书房里，是皇帝老儿的盆栽；\n",me);
		message_vision(query("name")+"说道：第二株生在黄山，黄山上哪儿最冷，这草便在哪儿；\n",me);
		message_vision(query("name")+"说道：第三株说远不远，说近不近，虽在人间，又在黄泉．．．\n",me);
		message_vision(query("name")+"说道：你只向那里去寻去问，便就对了。\n",me);
		REWARD_D->riddle_set(me,"天灵翡翠",5);
		return 1;
	}
	message_vision(query("name")+"挥手道：去、去、去，别扰我喝酒！\n",me);
	return 1;
}

void create()
{
        set_name("梅二先生", ({ "mei er", "meier"}) );        
        set("title",WHT"【妙郎中】"NOR);
        set("age", 65);
        set("long","
这人穿着件已洗的发白的蓝袍，袖子上胸口上，却又沾满了油腻，一双手的
指甲里也全是泥污，虽然戴着顶文士方巾，但头发却乱草般露在外面，一张
脸又黄又瘦，看来就象是个穷酸秀才。他就是七妙人中梅家二老的老二，梅
二先生的医术虽然比不上梅大，却也有白骨生肌之能，只可惜整天酗酒，武
功稀松平常，终于有一天被仇家黄河七蛟取了性命。阎王爷念其平素救人的
功德，由他在枉死城里逗留。不过，梅二先生从不白替人看病，即使是搭个
脉也是要收钱的。如果你真的有什么疑难杂症，可以向他打听治病的事儿。\n");
        
        set("combat_exp", 8000000);
        set("inquiry", ([
        	"黄山":		"我现在哪儿还能去爬山啊，你自己想办法吧。\n",
        	"御书房":	"什么？紫金殿关了？这样吧，你想办法竞选皇上，赢了就能进去了。\n",
        	"黄泉":		"啊呀，你只管找个死鬼去寻去问，便就对了。\n",		
        	"明烟草" : 	(: annie_drug :),
        	"受伤" : 	(: ask_me :),
             	"hurt" :	(: ask_me :),
             	"cure" :	(: ask_me :),
             	"recover":	(: ask_me :),
             	"治病":		(: ask_me :),
   	]));
    	      
        setup();
        carry_object("/obj/armor/ghost_cloth",(["name": "洗的发白的蓝袍",
    						"long": "一件洗的发白的蓝袍。\n",
    						"value": 0,
    						 ]))->wear();    
}


void init() {
	add_action("do_cure","cure");
	::init();
}



int ask_me(){
	int exp, cost, level;
	object me;
	
	me = this_player();
	if (!me->query("attr_apply/strength")
		&& !me->query("attr_apply/intelligence")
		&& !me->query("attr_apply/composure")
		&& !me->query("attr_apply/agility")
		&& !me->query("attr_apply/constitution")
		&& !me->query("attr_apply/karma")
		) {
		message_vision(CYN"梅二先生伸手搭住$N的脉门摸了摸，懒洋洋地说：快走快走，别坏了老夫的酒兴！\n"NOR,me);
		return 1;
	}
		
	cost = me->query("level")*2;
	message_vision(CYN"梅二先生伸手搭住$N的脉门，忽然大惊失色道：“病入膏肓！病入膏肓！
唯老夫方能救你，否则你还阳了还是个病猫！”\n"NOR,me);
	tell_object(me, WHT"恢复一点属性需要"+chinese_number(cost)+"两银子，你是否愿意？\n"NOR);
	tell_object(me, WHT"如果你在钱庄有足够的存款，输入<cure 属性名>\n"NOR);
	return 1;
}
	
int do_cure(string arg) {
	
	int exp, cost, level;
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
	cost = 200 * level;
	
	if (me->query("deposit")< cost)
		return notify_fail("你的钱庄存款不够"+ chinese_number(level*2) +"两银子，
看来你是个穷鬼。。。还是问哪个好心人（鬼）接济点吧。\n");		

	
	if (cost < 0)	cost= 0;
	me->add("deposit",-cost);
	
	message_vision(CYN"梅二先生哈哈大笑，朝你脸上吹了口气。。。。\n"NOR,me);
	tell_object(me,BLU"你只觉鬼气森森，一阵哆嗦后浑身却舒坦了许多。\n"NOR);
	me->add("attr_apply/"+cure,1);
	return 1;
}
	
int is_ghost()
{
	return 1;
}