inherit ITEM;
//inherit __DIR__"tutor";
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
                set("no_get", 1);
		set("no_shown", 1);
		set("teaching", "nonsense");
		set("teaching_limit", 400);
                set("material", "steel");
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
    
    	if( !(ob = present(teacher, environment(me))) )
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
        	write("这项技能你的程度已经不输你师父了。\n");
        	return 1;
    	}

    
    	required = 200;
    	if ( teaching == "sword" && my_class =="taoist") required = 120;
    	if ( teaching == "spear" && my_class =="official") required = 120;
    	if ( teaching == "xingyi-stick") required = 0;
    	if ( teaching == "tigerstrike") required = 0;
    		
    	if (my_skill < required ) {
        	write("依你目前的能力，没有办法学习这种技能。\n");
        	return 1;
    	}		
    
    	gin_cost = 100 / ( 10 + (int)me->query_int());

    	gin_cost *= pot;
    	gin_cost = gin_cost/2;

    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )   	{ 
    		write("你的潜能已经发挥到极限了，没有办法再成长了。\n");
      		return 1;
    	}

    	tell_object(me,"你向"+ob->name()+"请教有关「"+ SKILL_D(skill)->name() +"」的疑问。\n");

    	if( (int)me->query("gin") > gin_cost ) {
        if((my_skill * my_skill * my_skill)/10  >(int)me->query("combat_exp") ) {
            	printf("也许是因为缺乏经验，你对%s的回答总是无法领会。\n", ob->name() );
        } else {
            	printf("你听了%s的指导，似乎有些心得。\n",ob->name());
            	me->add("learned_points", pot);
            	amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
            	if((amount < -50) && (my_skill < 75)) amount = -50;

            	amount += SKILL_D(skill)->learn_bonus() +
                	(int)me->query_int() * (int)me->query_int() +
                	to_int(pow(to_float((int)me->query("combat_exp")),0.3));

            	amount = amount/50 + random(amount/50);
            	if (me->query("national")!="苗族")
			amount = amount *97/100;
	    	if ((int) me->query_skill(skill, 1)>320)    amount = amount*2/3;
	    	if ((int) me->query_skill(skill, 1)>350)    amount = amount/3;		
            	if( amount < 2) amount = 2;	
            	amount *= pot;
            	me->improve_skill(skill,amount);
        }
    	} else {
        	gin_cost = me->query("gin");
        	write("你今天太累了，结果什麽也没有学到。\n");
    	}
    
    	me->receive_damage("gin", gin_cost );
    
    	return 1;
}
    