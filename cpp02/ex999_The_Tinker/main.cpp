#include "Tinker.hpp"
#include "Sentry.hpp"

// The Tinker
// RULES

// !. The tinker can create sentry turrets
// 2. sentry turrets cannot be built by itself, they need the tinker
// 3. Only the tinker can reload the sentry
// 4. the tinker can build as many sentry as he want, each turret having a number when spawend
// %. the Tinker always have his toolBox
// 6. the Tinker can have NULL set for repairing_tool
// 7. repairing_tool can change (hammer, ratchet, wrench, welding station...)
// 8. the tinker need a repairing tool in his hand to repairing_sentry;

int main() {
	Tinker tinker;
	tinker.announce();


	return (0);
}