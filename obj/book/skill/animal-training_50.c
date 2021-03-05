inherit ITEM;

void create()
{
	set_name("训兽术", ({ "book", "animal-training book"}));
	set_weight(600);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    	set("unit", "本");
	    	set("long",  "这是一本关于训兽术的书。\n");
	    	set("value", 100);
	    	set("no_transfer",1);
		set("material", "paper");
	    	set("skill", ([
	            	"name": "animal-training",
	            	"exp_required": 100000,
	            	"sen_cost": 10,
	            	"difficulty": 35,
	            	"max_skill": 50,
	    	]) );
	}
}