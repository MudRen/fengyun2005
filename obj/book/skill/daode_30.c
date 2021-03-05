// sinny@fengyun
inherit ITEM;
void create()
{
        string *names = ({
                "【中庸】", "【荀子之修身篇】", "【荀子之劝学篇】",
                "【荀子之解蔽篇】", "【孝经】"
        });

        set_name( names[random(sizeof(names))], ({ "ethic book","book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是知书达礼的文人学者常看的先秦典籍。\n");
        set("value", 100);
        set("skill", ([
                "name":         "daode", 
                "exp_required": 5000,    
                "sen_cost":     15,      
                "difficulty":   30,                                              
                "max_skill":    29       
        ]) );
}
