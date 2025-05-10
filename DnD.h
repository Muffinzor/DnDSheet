//
// Created by leoin on 2025-05-10.
//

#ifndef DND_H
#define DND_H

namespace DnD {
    enum class Class {
        None,
        Fighter,
        Wizard,
        Rogue,
        Cleric,
        Paladin,
        Barbarian,
        Bard,
        Sorcerer,
        Ranger,
        Druid,
        Monk,
        Warlock
    };

    inline std::string class_to_string(const Class class_) {
        switch (class_) {
            case Class::Fighter: return "Fighter";
            case Class::Wizard: return "Wizard";
            case Class::Rogue: return "Rogue";
            case Class::Cleric: return "Cleric";
            case Class::Paladin: return "Paladin";
            case Class::Barbarian: return "Barbarian";
            case Class::Bard: return "Bard";
            case Class::Sorcerer: return "Sorcerer";
            case Class::Ranger: return "Ranger";
            case Class::Druid: return "Druid";
            case Class::Monk: return "Monk";
            case Class::Warlock: return "Warlock";
        }
        return "";
    }

    enum class Race {
        None,
        Human,
        Elf,
        Half_Elf,
        Half_Orc,
        Dwarf,
        Halfling,
        Gnome,
        Tiefling,
        Drow,
        Dragonborn
    };

    inline std::string race_to_string(const Race race_) {
        switch (race_) {
            case Race::Human: return "Human";
            case Race::Elf: return "Elf";
            case Race::Half_Elf: return "Half_Elf";
            case Race::Half_Orc: return "Half_Orc";
            case Race::Dwarf: return "Dwarf";
            case Race::Gnome: return "Gnome";
            case Race::Tiefling: return "Tiefling";
            case Race::Drow: return "Drow";
            case Race::Dragonborn: return "Dragonborn";
            case Race::Halfling: return "Halfling";
        }
        return "";
    }
    inline std::string race_bonuses(const Race race_) {
        switch (race_) {
            case Race::Human: return "+1 Str +1 Cha";
            case Race::Elf: return "+2 Dex";
            case Race::Half_Elf: return "+1 Dex +1 Cha";
            case Race::Half_Orc: return "+2 Str";
            case Race::Dwarf: return "+2 Con";
            case Race::Dragonborn: return "+1 Str +1 Wis";
            case Race::Halfling: return "+1 Dex +1 Con";
            case Race::Gnome: return "+1 Con +1 Int";
            case Race::Tiefling: return "+1 Int +1 Cha";
            case Race::Drow: return "+1 Dex +1 Int";
        }
    }
}

#endif //DND_H
