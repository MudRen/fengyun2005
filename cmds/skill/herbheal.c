/*	Herb heal by silencer@fy4.

compared it with normal healing pills
1. 2 silver 狗皮膏药 					40 sen
2. 3 silver 云南白药，大风丸，虎骨丸 			100kee/50sen/50gin
3. 10 silver 熊掌/人参/鹿茸  				300kee/200gin/200sen
4. 60 silver	七色雨虹花/三叶凤尾草/雪芝  		1500kee/1000sen/1000gin
5. 200 silver	九花玉露丸/白云熊胆丸/翠袖护心丹	5000kee/2500sen/2500gin


all can be collected by knight player.

L 100 herb, can be bought
type 1: herb_a: "龙胆草","谷精草","金钱草","地耳草","灯心草", 	
	Level 100, base_value effect 500(2s)-1000(4s)-1500(6s)-2000(8s)-2500(10s) kee
type 2: herb_b: " "木香","青木香","檀香",			
	Level 100, base_value effect 500(2s)-1000(4s)-1500(6s) sen/gin

L Level 150 herb random_drop 
type 1: herb_c: "冬虫夏草","紫河车","七叶龙爪花",  
	random(3) drop, knight 3000, 3500, 4000 kee
type 5: herb_d: "白花蛇草","七心海棠","罂粟叶",    poison self-made weapon..... 
	L75(75), L100 (150), L150 (200), L180(250), L200(300)
	2s-4s-5s-6s-7s	
type 4  herb_e: "金银花"	depoison	20s

L 200 herb
type 3: herb_f: "灵芝","紫藤叶"	random drop    4000/2000/2000 cure poison, heal both value.

Level: requirement for use herb
type : cure,  full, poison, depoison,
field:  kee/gin/sen
effect: amount that it heals, or it poisons,

*/

#include <ansi.h>
#include <condition.h>
inherit "/daemon/condition/generic_condition";
inherit F_CLEAN_UP;

int main(object me, string arg){
        
        int level, herb_level, effect;
        string type, field;
        
        string plant;
        object herb;
        
	if( !arg || sscanf(arg, "with %s", plant)!= 1 ) 
		return	notify_fail("指令格式：herbheal with <药草名>\n");

        if (me->is_busy())
        	return notify_fail("你现在正忙着，没空疗伤。\n");
        	
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

	level = me->query_skill("herb",1);
	if(level < 50 )
                return notify_fail("至少需要50级药道才能辨别药草的用途。\n");

	herb = present(plant,me);
	if (!herb)
		return notify_fail("你身上没有携带"+plant+"\n");
	
	type = herb->query("type");
	if (type!="cure" && type!="full" && type!="depoison")
		return notify_fail(herb->name()+"不能用来疗伤。\n");
	           
        herb_level = herb->query("level");
        if (level < herb_level )
        	return notify_fail("你对此种药草的性能尚不了解，无法用其来疗伤。\n");
        
        if(me->query("force")<200)
        	return notify_fail("运用药道需要200点真气。\n");
        me->add("force", -200);
        me->force_status_msg("force");
                        
        write( HIG "你取出"+ herb->name() + HIG"放在口中嚼烂，全身放松，坐下来开始将真气在经脉中缓缓流动。\n" NOR);
        message("vision", HIG + me->name() + "坐下来运起药道心法疗伤，头上冒出缕缕白气，
不久，吐出一口瘀血，脸色看起来好多了。\n"NOR,environment(me), me);
	
	field = herb->query("field");
	if (type == "cure")
	{
		switch (field) {
			case "kee": 	effect = herb->query("effect");
					me->receive_curing("kee", effect);
					tell_object(me,"你的气血治愈了"+effect+"点。\n");
					break;
			case "sen":	
			case "gin": 	effect = herb->query("effect");
					me->receive_curing("gin",effect);
					me->receive_curing("sen",effect);
					tell_object(me,"你的精力和心神治愈了"+effect+"点。\n");
					break;
			default:	tell_object(me,"如果你看到这句话，请报告巫师。\n");
		}
	}
	if (type == "full")
	{
		switch (field) {
			case "kee": 	effect = herb->query("effect");
					me->receive_fulling("kee", effect);
					tell_object(me,"你的气血回复了"+effect+"点。\n");
					break;
			case "sen":	
			case "gin": 	effect = herb->query("effect");
					me->receive_fulling("gin",effect);
					me->receive_fulling("sen",effect);
					tell_object(me,"你的精力和心神回复了"+effect+"点。\n");
					break;
			default:	tell_object(me,"如果你看到这句话，请报告巫师。\n");
		}
	}
	if (field == "depoison")
		me->clear_condition();		
	if (field == "depoisonx")
		me->clear_condition_type(LOW_POISON);	        

        herb->add_amount(-1);
        me->start_busy(2);
        return 1;
}
 
int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	herbheal with <药草名> [0m
[0;1;37m────────────────────────────────[0m   

快活林弟子的专长，利用药草熏疗伤口，为武林中疗伤圣术。
（至少需要50级药道）

不同的药草有不同的药效，药道越高，对药草的了解就越深刻。
药草在快活林和风云城都有出售，可用ｓａｍｐｌｅ指令察看
其功效。

[0;1;37m────────────────────────────────[0m   
 
HELP
    );
    return 1;
}
 
 