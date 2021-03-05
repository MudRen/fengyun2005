// Not enabled in game .. Silencer@fengyun workgroup	June.2005
				
#include <ansi.h>
inherit ITEM;

string description();

void create()
{
        set_name("领悟样板", ({ "draft" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
		set("teaching", "advanced-parry");
		set("teaching_limit", 150);
		set("required_exp", 3000000);
                set("material", "paper");
        }
}

string description() {
	string msg,required ;
	
	required = query("required_class") ? F_MASTER->query_chinese_class(query("required_class"))+"弟子，"
			: "";
	required += query("required_level") ? " "+(string)(query("required_level"))+"级同名武功" 
			: "";		
	
	msg = YEL"一本泛黄的薄册，虽然已经有年头了，书页仍然完好无损。\n"NOR;
	msg += sprintf(WHT"武功秘籍：\t\t%s（%s）\n"
			 "等级：    \t\t%d级\n"
			 "学习条件：\t\t\%s\n"
			 "特殊功用：\t\t%s\n"NOR,
			query("name"),query("teaching"),
			query("teaching_limit"),
			required,
			query("perform_name")
			);
	
	return msg;
}

/*

int query_autoload() { return 1; }

void init()
{
   	add_action("do_master","master");
}
    
int do_master(string arg)
{
    	string skill, teacher, master, teaching;
    	object me, ob, *list;
    	int my_skill, gin_cost, max_skill, required_exp;
    	string target, cardname, my_class;
    	int i;
    	int amount=0, pot;
    
    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 ) {
        	write("指令格式：master "+query("teaching")+" from book with <潜能点>\n");
        	write("领悟时携带的武功秘籍不能超过一本。\n");
        	return 1;
        }
        
    	me = this_player();
    	
    	if( !(ob = present(teacher, me)) )
	        return 0;

    	if ( pot <=0 )
        	return 1;
    
    	if( me->is_fighting() ) {
    		write("战斗中不能领悟技能。\n");
        	return 1;
    	}
    	
// Start learning from tutor
    	teaching = (string) query("teaching");
    	my_class = me->query("class");
    	
    	if( skill != teaching )  {
        	write("你无法从这本书上领悟到这项技能。\n");
        	return 1;
        }

    	my_skill = (int) me->query_skill(skill, 1);
    	max_skill = (int) query("teaching_limit");
    	if( my_skill >= max_skill ) {
        	write("你已经彻底领悟了这本书上的武功，再往后只有靠自己钻研了。\n");
        	return 1;
    	}

	if (query("required_class"))
    	if (my_class != query("required_class")) {
    		write("你未掌握该门派的武功，无法领悟"+SKILL_D(skill)->name()+"。\n");
    		return 1;
    	}
   	
   	if (query("required_level"))
   	if (my_skill < query("required_level")) {
   		write("你的"+SKILL_D(skill)->name()+"火候不够，无法进一步领悟。（需"+query("required_level")+"级）\n");
   		return 1;
   	}
   	
    	required_exp = query("required_exp");
    	if (me->query("combat_exp") < required_exp )	{
        	write("你的实战经验太差，无法领悟此书中的高深武功。\n");
        	return 1;
    	}		
    
    	gin_cost = 100 / ( 10 + (int)me->query_int());
    	gin_cost *= pot;
    	gin_cost = gin_cost/2;

    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )    { 
    		write("你的潜能已经发挥到极限，没有办法再继续领悟了。\n");
      		return 1;
    	}

    	tell_object(me,"你打开书本，开始潜心思考「"+SKILL_D(skill)->name() +"」的关键所在。\n");

    	if( (int)me->query("gin") > gin_cost ) {
        	if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") ) {
            		printf("你苦苦思索，但也许是因为缺乏实战经验，总是在关键之处不明所以。\n", ob->name() );
        	} else {
            		printf("你依着书中的指导细细琢磨，似乎有些心得。\n");
            		me->add("learned_points", pot);
	            	amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
	            	if((amount < -50) && (my_skill < 75)) amount = -50;
	            	amount += SKILL_D(skill)->learn_bonus() +
	                	(int)me->query_int() * (int)me->query_int() +
	                	to_int(pow(to_float((int)me->query("combat_exp")),0.3));
		        amount = amount/50 + random(amount/50);
		    	if ((int) me->query_skill(skill, 1)>320)    amount = amount*2/3;
		    	if ((int) me->query_skill(skill, 1)>350)    amount = amount/3;		
	            	if( amount < 2) amount = 2;	
	            	amount *= pot;
	            	me->improve_skill(skill,amount);
        	}
    	} else {
        	gin_cost = me->query("gin");
        	write("你今天太累了，结果什麽也没有能领悟出来。\n");
    	}
    
    	me->receive_damage("gin", gin_cost);
    
    	return 1;
}
*/    