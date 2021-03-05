// 本文档为6.28.2003版本的fycycle tutor.

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("无知学习样板", ({ "tutor" }));
	set_weight(6000000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
	set("unit", "个");
	set("long",
			"一个学习样板，你似乎可以从它这里学点什么。\n你细看之下，觉得这个东西不过是个垃圾。\n");
	set("value", 0);
	set("no_drop", 1);
	set("no_get", 1);
	set("no_sell", 1);
	set("teaching", "nonsense");
	set("teaching_limit", 400);
	set("material", "paper");
	}
}

void init()
{
   	add_action("do_learn","learn");
}
    
int do_learn(string arg)
{
    	string skill, teacher, master, teaching;
    	object me, ob, *list;
    	int my_skill, gin_cost, max_skill, required;
    	string target, cardname, my_class;
    	int i;
    	int amount=0, pot;
    
    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 )
        	return notify_fail("指令格式：learn <技能> from <某人> with <潜能点>\n");
    
    	me = this_player();
    	if( me->is_fighting() )
        	return 0;
    
    	if( !(ob = present(teacher, me)) )
        	return 0;

    	if ( pot <=0 )
        	return 0;
    
// Start learning from tutor
    	teaching = (string) query("teaching");
    	my_class = me->query("class");
    	if( skill != teaching )  {
        	write("这项技能你恐怕必须找别人学了。\n");
        	return 1;
        }

    	my_skill = (int) me->query_skill(skill, 1);

    	max_skill = (int) query("teaching_limit");
    	if( my_skill >= max_skill ) {
        	write("这项技能你的程度已经不比书上的记载低了。\n");
        	return 1;
    	}
  
    	required = query("teaching_require");
    		
    	if (my_skill < required ) {
        	write("依你目前的能力，没有办法学习这种技能（需"+required+"级）\n");
        	return 1;
    	}		
    
       	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )   	{ 
    		write("你的潜能已经发挥到极限了，没有办法再成长了。\n");
      		return 1;
    	}

    	tell_object(me,"你在"+ob->name()+"上阅读有关「"+ SKILL_D(skill)->name() +"」的讯息。\n");

    	if((my_skill * my_skill * my_skill)/10  >(int)me->query("combat_exp") ) {
            	printf("也许是因为缺乏经验，你对%s上的文字总是无法领会。\n", ob->name() );
        } else {

// WARNING ON	Seperated set of variables so it won't mess up with the old thing =============

			mapping learned_skill_points;
			int leftover, j, a_cost,a_amount, a_total;
						
			learned_skill_points=me->query_learned();
			if (mapp(learned_skill_points))
				leftover = learned_skill_points[skill];
			else
				leftover = 0;
			j = me->query_skill(skill,1);
			
			if (me->query_int()<=40)
				a_amount = (400+30* me->query_int()) *2 * 100;
			else
				a_amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
	        	        
	        if (me->query("national")=="苗族")	
	        	a_amount = a_amount + a_amount/20;	// 民族特性      	            	    	
	        a_amount = a_amount / SKILL_D(skill)->skill_difficulty();        	                 	
	       	if( a_amount < 1) a_amount = 1;		// 至少1：1 
	       	          
	        a_total = (j+1)*(j+1)+1 - leftover;
	        a_cost = a_total*100/a_amount+1;
			
			if (a_cost < 0)
				a_cost = 1;
				
			if (a_cost < pot) { 
				tell_object(me, HIR"风云友好提示：您所输入的潜能数（"+pot+"）大于升级所需（"+a_cost+"）点！\n"NOR);
				tell_object(me,HIR"系统自动调整所用潜能数为"+a_cost+"点。\n"NOR);
				pot = a_cost;
			}
			
// WARNING OFF =================================================================================

	          	printf("你看了%s的描述，似乎有些心得。\n",ob->name());
            	me->add("learned_points", pot);
            	me->add("annie/skill_cost/"+skill,pot);
            	
            	if (me->query_int()<=40)
            		amount = (400+30* me->query_int()) *2 * pot;
            	else
            		amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*pot) ;
            		
            	if (me->query("national")=="苗族")	
            		amount = amount + amount/20;	// 民族特性
            	
            	amount = amount / SKILL_D(skill)->skill_difficulty();
            	            	           	                 	
            	if( amount < 1) amount = 1;		// 至少1：1     

// DEBUG on
		if (wizardp(me) && me->query("env/debug")) {
			write("skill difficulty is "+ SKILL_D(skill)->skill_difficulty() + "\n");
			write("learning efficiency is: 1 point 潜能 == " + amount + "\n");
		}
// DEBUG off
            	            	
            	me->improve_skill(skill,amount);
        }
    	
    	return 1;
}
    
    