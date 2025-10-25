#pragma once

#include <GameLibraryAPI.h>
#include <Runtime/Core/CoreMinimal.h>
#include <Engine/Core/CoreMinimal.h>

namespace Strand
{
    STRAND_CLASS();
    class GAME_API TestClass : public IReflectable
    {
        STRAND_OBJECT(TestClass);
    public:
        TestClass();
        ~TestClass() override = default;

        void SetStr(const String& str) { m_testString = str; }
        const String& GetStr() const { return m_testString; }

    private:
        String m_testString;
    };
}