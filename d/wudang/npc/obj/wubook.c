// book.c

inherit ITEM;

void create()
{
	int	i;
	
	string *names = ({
	    "「易经」", "「太极拳谱」", "「五行身法图」", "「太极内功入门」"
	});
	
	string *skills= ({
	    "changelaw", "taiji", "five-steps", "taijiforce"
	});
	
	i = random(4);
	set_name( names[i], ({ "book" }));
	set_weight(100);
	set("unit", "本");
	set("long", "这是一本修练武当派入门武功的书籍。\n");
	set("skill", ([
	    "name":                 skills[i],
	    "exp_required": 0,                
	    "sen_cost":             40,     
	    "difficulty":   30,            
	    "max_skill":    10           
	                                
	]) );
	::init_item();
}
